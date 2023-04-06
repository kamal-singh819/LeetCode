class Solution {
private:
    bool isPossible(int div, vector<int> &nums, int threshold){
        int thres = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%div == 0) thres += nums[i]/div;
            else thres += (1 + nums[i]/div); //ceil value
        }
        return thres <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //Try for each divisor = 1,2,3,4,...... Linearly BUT IT GIVES TLE
        //use binary Search
        int low = 1; //lowest divisor 
        int high = 1e6; //max of nums[i]
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, nums, threshold)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
