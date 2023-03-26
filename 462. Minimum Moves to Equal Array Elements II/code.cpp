class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        int mid = nums[(0+n-1)/2];

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += abs(nums[i]-mid);
        }
        return ans;
        
    }
};
