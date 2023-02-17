class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] != 0){
                i++;
                continue;
            }
            long long cntZeros = 0;
            while(i<n && nums[i] == 0){
                cntZeros++;
                i++;
                if(i == n)
                    break;
                if(nums[i] != 0){
                    i--;
                    break;
                }
            }
            ans += (cntZeros*(cntZeros+1))/2;
            i++;
        }
        return ans;
        
    }
};
