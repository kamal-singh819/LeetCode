class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        long long subsum = 0;
        int i=0;
        int j=0;
        while(j < nums.size()){
            subsum += (long long) nums[j];
            mp[nums[j]]++;
            if(j-i+1 == k){
                if(mp.size() == k) ans = max(ans, subsum);
            
                if(mp[nums[i]] <= 1) mp.erase(nums[i]);
                else mp[nums[i]]--;
                subsum -= nums[i];
                i++;
            }
            j++;
        }
        return ans; 
    }
};
