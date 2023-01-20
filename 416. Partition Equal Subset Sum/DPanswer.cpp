class Solution {
public:
    bool subSetSum(vector<int> &nums, int sum, int n){
        vector<vector<int>> dp(n+1, vector<int> (sum+1));
//this is initialization of tabulation (DP)----
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;    
            }
        }
//main code of DP------------------
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];

                else
                    dp[i][j] = dp[i-1][j];    
            }
        }

        return dp[n][sum];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;

        sum = sum/2;

        return subSetSum(nums, sum, n);       
    }
};
