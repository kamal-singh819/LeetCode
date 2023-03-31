class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;

        int ans = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(x >= k) continue;
            if(mp.count(k-x) && x == k-x && mp[x] >= 2){
                ans++;
                mp[x] -= 2;
            }
            else if(mp.count(k-x) && x != k-x && mp[k-x] >= 1 && mp[x] >= 1){
                ans++;
                mp[x]--;
                mp[k-x]--;
            }
        }
        return ans;
    }
};
