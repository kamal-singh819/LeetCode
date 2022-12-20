//Data Structure used- Queue and Unordered_map

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            vector<int> v = rooms[top];
            for(int i=0; i<v.size(); i++){
                if(visited[v[i]] == false){
                    q.push(v[i]);
                    visited[v[i]] = true;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i] == false)
                return false;
        }
        return true;

        
    }
};

