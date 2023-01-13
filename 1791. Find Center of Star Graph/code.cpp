class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int adjSiz = adj.size();

        int ans = 0;

        for(auto x : adj){
            vector<int> temp = x.second;
            int p = x.first;
            if(adjSiz-1 == temp.size()){
                ans = p;
                break;
            }
        }
        return ans;
        
    }
};
