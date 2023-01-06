//Using BFS------------------------------

class Solution {
public:
    void createAdjList(unordered_map<int, vector<int>>&adjList, vector<vector<int>>& edges){
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void bfsTraversal(unordered_map<int, vector<int>>&adjList, int s, int d, unordered_map<int, bool> &visited){
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto x : adjList[f]){
                if(visited[x] == false){
                    q.push(x);
                    visited[x] = true;
                }
            }
            if(visited[d] == true)
                break;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int> >adjList;
        unordered_map<int, bool> visited;

        createAdjList(adjList, edges);

        for(int i=0; i<n; i++){
            if(visited[i] == false){
                bfsTraversal(adjList, source, destination, visited);
            }
        }

        return visited[destination];
        
    }
};
