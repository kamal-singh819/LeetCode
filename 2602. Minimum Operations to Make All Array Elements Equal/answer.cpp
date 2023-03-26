class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        vector<long long> ans(m);
        unordered_map<int, pair<long long, long long>> mp;

        sort(nums.begin(), nums.end());
        ////////////
        long long sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        long long x = 0;
        for(int i=0; i<n; i++){
            if(i == 0) mp[i] = {0, sum};
            else{
                mp[i] = {x, sum-x};
            } 
            x += nums[i];
        }
        mp[n] = {sum, 0};
        //////////////

        for(int i=0; i<m; i++){
            long long p = queries[i];
            long long ind = lower_bound(nums.begin(), nums.end(), p) - nums.begin();

            if(ind == n){ //out of the bound of nums
                long long left = mp[ind].first;
                ans[i] = (ind*p) - left;
                continue;
            }
            long long left = mp[ind].first;
            long long right = mp[ind].second;
            
            long long pos = right - ((n-ind)*p);
            long long neg = (ind*p) - left;

            ans[i] = pos+neg;
        }
        return ans;
    }
};
