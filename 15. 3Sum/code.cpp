class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        //first approach is using 3 loop but this is not good T.C = O(N^3)
        //second approach is using map
        //this is third approach
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            int x = nums[i];
            int j = i+1;
            int k = n-1;
            while(j < k){
                if(nums[j]+nums[k] == -x){
                    ans.push_back({x, nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                    while(nums[k] == nums[k-1] && j < k) k--;
                    k--;
                }
                else if(nums[j]+nums[k] < -x){
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                }
                else{
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                }
            }
            while(i < n-2 && nums[i] == nums[i+1]) i++;
        }
        return ans;

        
    }
};



