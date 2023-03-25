class Solution {
private:
    void dfs(int s, vector<bool> &visited, unordered_map<int, vector<int>> &adj, long long &countNodeComp){
        visited[s] = true;
        countNodeComp++;
        for(int x : adj[s]){
            if(!visited[x]) dfs(x, visited, adj, countNodeComp);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        //adjacency List--------------
        unordered_map<int, vector<int>> adj;
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        //dfs
        long long countNodeComp = 0;
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj, countNodeComp);
                cout<<countNodeComp<<" ";
                ans += (countNodeComp*(n-countNodeComp));
                countNodeComp = 0;
            }
        }
        return ans/2;   
    }
};
