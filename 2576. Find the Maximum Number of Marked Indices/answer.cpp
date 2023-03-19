class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n/2;
        int ans = 0;
        while(i<n/2 && j < n){
            if(j < n && nums[j] != -1 && 2*nums[i] <= nums[j]){
                nums[j] = -1;
                nums[i] = -1;
                i++;
                j++;
                ans += 2; //because pair of two are marked
            }
            else if(j < n && !(2*nums[i] <= nums[j])){
                j++;
            }
        }
        return ans;
    }
};
