class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int i=0;
        int j=n-1;

        while(i < j){
            if(nums[i] != val && nums[j] != val)
                i++;
            else if(nums[i] == val && nums[j] != val){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else if(nums[i] != val && nums[j] == val){
                i++;
                j--;
            }
            else if(nums[i] == val && nums[j] == val)
                j--;
        }  
        for(int i=n-1; i>=0; i--){
            if(nums[i] == val)
                nums.pop_back();
        }

        return nums.size();
        
    }
};
