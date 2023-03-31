//////////////////////////  BFS Solution   /////////////////// we can simply do this without dfs and bfs
class Solution {
    private:
    void bfs(int s, vector<vector<int>> &adj, vector<bool> &visited, int &ans, int k, vector<int>& vals){
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while(!q.empty()){
            int f = q.front(); //front of the queue
            q.pop();
            vector<int> val;
            int rootval = vals[f];
            for(int x : adj[f]){
                val.push_back(vals[x]);
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
            sort(val.begin(), val.end(), greater<>());
            int i=0;
            int p = 0;
            int s = 0;
            while(i < val.size() && p < k){
                if(val[i]>0) s += val[i];
                else break;
                i++;
                p++;
            }
            ans = max(ans, s+rootval);
        }
    }
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        int ans = INT_MIN;
        vector<vector<int>> adj(n);
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        //bfs
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(i, adj, visited, ans, k, vals);
            }
        }
        return ans;
    }
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  Without using BFS or DFS  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n); //stores vals like 3 -> 2,10,-10,-20 (example -1)
        //u -> vals[v] and v -> vals[u] 
        for(auto edge : edges){
            adj[edge[0]].push_back(vals[edge[1]]);
            adj[edge[1]].push_back(vals[edge[0]]);
        }  

        int ans = INT_MIN;
        for(int node=0; node<n; node++){
            int s = vals[node];
            sort(adj[node].begin(), adj[node].end(), greater<>());
            int i=0, p=0;
            while(i < adj[node].size() && p < k){
                if(adj[node][i] > 0) s += adj[node][i];
                else break;
                i++;
                p++;
            }
            ans = max(ans, s);
        }  
        return ans;   
    }
};
