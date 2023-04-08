class Solution {
private:
    bool isPossibleThisPenality(int penality, int &maxop, vector<int> &nums, int &n){
        int op = 0;
        for(int i=0; i<n; i++){
            if(nums[i]%penality == 0) op += nums[i]/penality - 1;
            else op += nums[i]/penality;
            if(op > maxop) return false;
        }
        return op <= maxop;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        //we can check for penality 1,2,3,4,5........etc but it will give TLE
        //Use Binary Seach---
        int n = nums.size();
        int minPenality = 1;
        int maxPenality = 1e9;
        int ans = -1;
        while(minPenality <= maxPenality){
            int mid = minPenality + (maxPenality - minPenality)/2;
            if(isPossibleThisPenality(mid, maxOperations, nums, n)){
                ans = mid;
                maxPenality = mid-1;
            }
            else minPenality = mid+1;
        }
        return ans;  
    }
};
