//                               G  E  N  E  R  A  L    T  H  I  N  K  I  N  G

class Solution {
private:
    void solve(int start, vector<bool> &visited, unordered_map<int, vector<int>> &mp){
        visited[start] = true;
        for(int x : mp[start]){
            if(!visited[x]) solve(x, visited, mp);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int> > mp; //adjacency list--
        for(auto x : roads){
            mp[x[0]].push_back(x[1]); //u : v
            mp[x[1]].push_back(x[0]); //v : u
        }
        vector<bool> visited(n+1, false);
        solve(1, visited, mp); //marks true to all the nodes which node can be visited from 1

        int ans = INT_MAX;
        for(int i=0; i<roads.size(); i++){
            int k = roads[i][0];
            if(visited[k]){
                ans = min(ans, roads[i][2]);
            }
        }
        return ans;
    }
};


//                                           D  F  S                                                 //
class Solution {
private:
    int dfs(int s, unordered_map<int, vector<pair<int, int>>> &mp, vector<bool> &visited, int &ans){
        visited[s] = true;
        for(auto x : mp[s]){
            ans = min(ans, x.second);
            if(!visited[x.first]){
                visited[x.first];
                int p = dfs(x.first, mp, visited, ans);
                ans = min(ans, p);
            }
        }
        return ans;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>> > mp; //adjacency list--
        for(auto x : roads){
            mp[x[0]].push_back({x[1], x[2]}); //u : {v, distance}
            mp[x[1]].push_back({x[0], x[2]}); //v : {u, distance}
        }
        vector<bool> visited(n+1, false);
        int ans = INT_MAX;
        return dfs(1, mp, visited, ans);
    }
};



//                                                              B F S                                       //
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>> > mp; //adjacency list--
        for(auto x : roads){
            mp[x[0]].push_back({x[1], x[2]}); //u : {v, distance}
            mp[x[1]].push_back({x[0], x[2]}); //v : {u, distance}
        }
        
        int ans = INT_MAX;
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto x : mp[f]){
                ans = min(ans, x.second);
                if(!visited[x.first]){
                    q.push(x.first);
                    visited[x.first] = true;
                }
            }
        }
        return ans;
    }
};
