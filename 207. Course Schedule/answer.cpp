//Use the concept of detecting the loop/cycle in directed graph

class Solution {
private:
    bool dfsSolution(vector<vector<int>> &adjList, int s, vector<bool> &visited,vector<bool> &currVisited){
        visited[s] = false;
        currVisited[s] = false;
        for(auto x : adjList[s]){
            if(visited[x]){
                if(!dfsSolution(adjList, x, visited, currVisited))
                    return false;
            }
            else if(visited[x] == false && currVisited[x] == false)
                return false;
        }
        currVisited[s] = true;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        int n = numCourses;
        vector<bool> visited(n, true);
        vector<bool> currVisited(n, true);
        for(int i=0; i<n; i++){
            if(visited[i]){
                if(!dfsSolution(adjList, i, visited, currVisited))
                    return false;
            }
        }
        return true;    
    }
};
