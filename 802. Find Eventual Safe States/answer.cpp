//answer vector will store terminal node and the nodes which are not participating in any loop and cycle....

//TERMINAL NODE : A node which has outdegree is 0....
class Solution {
public:
    bool dfsCycle(int s,vector<bool> &visited,vector<bool> &currVisited,vector<bool>&trackCycle,vector<vector<int>>& graph){
        visited[s] = true;
        currVisited[s] = true;
        for(auto x : graph[s]){
            if(!visited[x]){
                if(dfsCycle(x,visited,currVisited,trackCycle,graph))
                    return trackCycle[s] = true;
            }
            else if(visited[x] == true && currVisited[x] == true)
                return trackCycle[s] = true;
        }
        currVisited[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;

        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> currVisited(n, false);
        vector<bool> trackCycle(n, false);

        for(int i=0; i<n; i++){
            if(! visited[i]){
                dfsCycle(i,visited,currVisited,trackCycle, graph);
            }
        }

        for(int i=0; i<n; i++){
            if(trackCycle[i] == false)
                ans.push_back(i);
        }

        return ans;
        
    }
};
