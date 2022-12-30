//Using DFS---------------------------
class Solution {
public:
    void dfsFunction(int source, int target, vector<vector<int>>& graph, vector<int> &path, vector<vector<int>> &ans){
        path.push_back(source);
        if(source == target)
            ans.push_back(path);
        else{
            for(auto i : graph[source]){
                dfsFunction(i, target, graph, path, ans);
            }
        }
        path.pop_back();    
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0;
        int target = graph.size()-1;
        vector<vector<int>> ans;
        vector<int> path;
        dfsFunction(source, target, graph, path, ans);
        return ans;
        
    }
};
