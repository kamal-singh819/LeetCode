### Approach - 1 Code:   Time Complexity : O(n^2) and Space Complexity : O(n)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mxCnt = 0;
        for(int element : nums){
            mp[element]++;
            mxCnt = max(mxCnt, mp[element]);
        }
        vector<vector<int>> ans(mxCnt);
        
        for(auto x : mp){
            int val = x.first;
            int freq = x.second;
            for(int i=0; i<freq; i++) ans[i].push_back(val);
        }
        return ans;   
    }
};


### Approach - 2 Code:    Time Complexity : O(n) and Space Complexity : O(n)
### This approach is efficient compare than Approach-1
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);

        vector<vector<int>> ans;
        for(int x : nums){
            int f = freq[x];
            if(f >= ans.size()) ans.push_back({}); //add an empty row
            ans[f].push_back(x);
            freq[x]++;
        }
        return ans;   
    }
};
