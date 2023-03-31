class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans = INT_MIN;
        int i=0;
        while(i<n){
            int s = nums[i];
            int j = i+1;
            while(j < n && nums[i] < nums[j]){
                s += nums[j];
                i++;
                j++;
            }
            ans = max(ans, s);
            i++;
        }
        return ans;  
    }
};
