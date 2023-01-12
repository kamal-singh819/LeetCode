//Using DFS----------------------------------------

class Solution {
    private:
    void createAdjList(vector<vector<int>> &edges, vector<vector<int>> &adjList){
        for(auto x : edges){
            int u = x[0];
            int v = x[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void dfsSolution(int current,int parent,vector<vector<int> > &adjList, string &labels, unordered_map<char, int> &mp,vector<int> &ans){
        int prevCount = mp[labels[current]]; //we will keep a previous Count for label of each node
        mp[labels[current]]++;

        for(int &child : adjList[current]){
            if(child == parent)
                continue;

            dfsSolution(child, current, adjList, labels, mp, ans);    
        }
        ans[current] = mp[labels[current]] - prevCount;

    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjList(n);
        vector<int> ans(n,0);
        //vector<int> mp(26, 0);
        unordered_map<char, int> mp;
        int current = 0;
        int parent = -1; //to ignore the parent
        createAdjList(edges, adjList); //a function to create adjacency list---------
        dfsSolution(current, parent, adjList, labels, mp, ans);
        return ans;
        
    }
};
