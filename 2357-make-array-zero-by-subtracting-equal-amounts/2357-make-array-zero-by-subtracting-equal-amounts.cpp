class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) continue;
            int x = nums[i];
            ans++;
            for(int j=i; j<n; j++) nums[j] = nums[j] - x;
        }
        return ans;
        
    }
};