class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        int ans = maxi;
        for(int i=1; i<n; i++){
            if(nums[i] < 0)
                swap(maxi, mini);
            else if(nums[i] == 0){
                maxi = 1;
                mini = 1;
            }
            maxi = max(nums[i], maxi*nums[i]);
            mini = min(nums[i], mini*nums[i]);

            ans = max(ans, maxi);
        }
        return ans;
        
    }
};
