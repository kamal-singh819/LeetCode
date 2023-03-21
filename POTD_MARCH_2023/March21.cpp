class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i=0;
        while(i < nums.size()){
            long long countzeros = 0;
            while(i < nums.size() && nums[i] == 0){
                countzeros++;
                i++;
            }
            if(countzeros != 0) ans += (countzeros*(countzeros+1)/2);

            i++;
        }
        return ans;
    }
};
