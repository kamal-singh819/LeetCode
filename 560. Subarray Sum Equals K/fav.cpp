class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //can't use sliding window cozz negative numbers are present in nums---
        int n = nums.size();
        unordered_map<int, int> mp; //store prefix array sum--
        int sum = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum == k)
                count++;
            
            if(mp.find(sum-k) != mp.end())
                count += mp[sum-k];

            mp[sum]++;
        }
        return count;
        
    }
};
