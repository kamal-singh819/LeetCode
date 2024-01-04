class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        
        for(auto x : mp){
            int f = x.second; //frequency
            if(f == 1) return -1; //not possible to make array empty
            if(f%3 == 0) ans += f/3;
            else ans += f/3 + 1;
        }
        return ans;
    }
};
