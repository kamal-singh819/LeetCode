class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int ans = INT_MIN;
        while(j < n){
            if(k == 0 && nums[j] == 0){
                while(k == 0){
                    if(nums[i] == 1)
                        i++;
                    else{
                        k++;
                        i++;
                    }
                }
            }
            else{
                if(nums[j] == 1)
                    j++;
                else{
                    k--;
                    j++;
                }
            }
            ans = max(ans, j-i);
        }
       
        return ans;
        
    }
};
