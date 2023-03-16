//             USING SLIDING WINDOW

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int s = 0;
        while(j < n){
            s += nums[j];
            if(s >= target){
                while(s >= target){
                    ans = min(ans, j-i+1);
                    s -= nums[i];
                    i++;
                }
                j++;
            }
            else
                j++;
        }
        return ans == INT_MAX ? 0 : ans;   
    }
};
