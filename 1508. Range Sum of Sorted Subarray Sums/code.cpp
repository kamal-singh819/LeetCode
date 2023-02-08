class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        if(n == 1)
            return nums[0];
        int M = 1000000007;
        int ans = 0;
        vector<int> res;
        for(int i=0; i<n; i++){
            int s = 0;
            for(int j=i; j<n; j++){
                s = (s+ nums[j])%M;
                res.push_back(s);
            }
        }

        sort(res.begin(), res.end());

        for(int i=left-1; i<right && i<res.size(); i++){
            ans = (ans + res[i])%M;
        }
        return ans;
        
    }
};
