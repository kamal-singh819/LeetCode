class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto x : nums){
            for(int i=0; i<x.size(); i++){
                mp[x[i]]++;
            }
        }

        for(auto y : mp){
            if(y.second == n)
                ans.push_back(y.first);
        }

        sort(ans.begin(), ans.end()); 
        return ans;   
    }
};
