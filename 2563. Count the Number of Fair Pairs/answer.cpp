class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            int low = lower-nums[i]; //min value to search in nums
            int upp = upper-nums[i]; //max value to search in nums

            //apply binary search
            int lowBound = lower_bound(nums.begin()+(i+1), nums.end(), low) - nums.begin();
            int uppBound = upper_bound(nums.begin()+(i+1), nums.end(), upp) - nums.begin();

            //cout<<lowBound<<" "<<uppBound<<endl;
            ans += (uppBound-lowBound);
        } 
        return ans;
        
    }
};
