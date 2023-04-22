class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, pair<int, int>> mp;
        for(auto v : matches){
            mp[v[0]].first++;
            mp[v[1]].second++;
        }
        for(auto x : mp){
            if(x.second.second == 0) ans[0].push_back(x.first);
            if(x.second.second == 1) ans[1].push_back(x.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
