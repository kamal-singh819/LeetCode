class Solution {
private:
    void dfs(int s, unordered_map<int, vector<int> >&mp, vector<bool> &visited){
        visited[s] = true;
        for(int x : mp[s]){
            if(!visited[x]) dfs(x, mp, visited);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1) return -1; //not possible for sure..
        
        unordered_map<int, vector<int> > mp;
        for(auto x : connections){
            int u = x[0];
            int v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int components = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){  
            if(!visited[i]){
                components++;
                dfs(i, mp, visited);
            }
        }
        return components-1; 
    }
};
