class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int evenSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0)
                evenSum += nums[i];
        }
        vector<int> ans(n);
        //now traverse queries array
        for(int i=0; i<n; i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            if(nums[ind]%2 == 0){
                if(val%2 == 0) ans[i] = evenSum+val;
                else ans[i] = evenSum-nums[ind]; //as even nums[ind] is replaced with odd(nums[ind]+val)
                //update in nums
                nums[ind] += val;
                evenSum = ans[i];
            }
            else{
                if(val%2 != 0) ans[i] = evenSum + val + nums[ind];
                else ans[i] = evenSum;
                //update in nums
                nums[ind] += val;
                evenSum = ans[i];
            }
        }
        return ans;
        
    }
};
