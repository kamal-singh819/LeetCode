class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int i=0;
        for(int j=0; j<n; j++){
            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        return nums;  
    }
};
