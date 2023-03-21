class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;
        int i = 1;
        int ans = 0;
        while(i < n){
            bool flag = false;
            int count = 1;
            int diff = nums[i]-nums[i-1];
            while(i < n && nums[i]-nums[i-1] == diff){
                count++;
                i++;
                flag  = true;
            }
    //at least three elements  :       all subarrays   - subarrays of size 1 and 2
            if(count >= 3) ans += ((count*(count+1)/2) - (2*count - 1));
            //(because we need only more than or eqaul to 3 size subarray)
            if(flag == false) i++;
        }
        return ans;
    }
};
