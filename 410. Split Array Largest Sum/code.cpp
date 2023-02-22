class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++)
            total += nums[i];
        
        if(k == 1)
            return total;
        
        int maxx = *max_element(nums.begin(), nums.end());

        int s = maxx;  //start of the search space
        int e = total; // end of the search space

        while(s < e){
            int mid = s + (e-s)/2;
            
            long long add = 0;
            int countSubArray = 1;
            for(int x : nums){
                if(add+x > mid){
                    add = 0;
                    countSubArray++;
                }
                add += x;
            }

            if(countSubArray <= k)
                e = mid;
            else
                s = mid+1;
        }
        return s;
        
    }
};
