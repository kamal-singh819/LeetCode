//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfsCyclic(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsCalled){
        visited[src] = true;
        dfsCalled[src] = true;
        for(auto x : adj[src]){
            if(!visited[x]){
                bool cycleFound = dfsCyclic(x, adj, visited, dfsCalled);
                if(cycleFound == true)
                    return true;
            }
            else if(visited[x] == true && dfsCalled[x] == true)
                return true;
        }
        dfsCalled[src] = false;  //backtrack
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> dfsCalled(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = dfsCyclic(i, adj, visited, dfsCalled);
                if(ans)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends