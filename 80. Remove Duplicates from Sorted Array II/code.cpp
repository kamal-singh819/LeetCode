class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <=2)
            return n;
        
        int left = 2; //two instances of an element should be present in the array
        for(int i=2; i<n; i++){
            if(nums[i] != nums[left-2]){
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
        
    }
};
