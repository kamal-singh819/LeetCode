class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> mp;
        string temp = "";
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                temp += (to_string(grid[i][j]) + "_");
            }
            mp[temp]++;
            temp.clear();
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=0; j<n; j++) str += (to_string(grid[i][j]) + "_");
            if(mp.count(str)) ans += mp[str];
            str.clear();
        }
        return ans;
    }
};