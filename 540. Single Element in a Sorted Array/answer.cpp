class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[n-1] != nums[n-2])
            return nums[n-1];        
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        int ans = 0;
        while(s <= e){
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                ans = nums[mid];
                return ans;
            }
            else if((mid+1)%2==0 && nums[mid] == nums[mid-1])
                s = mid+1;

            else if((mid+1)%2 != 0 && nums[mid] == nums[mid+1])
                s = mid+1; 

            else
                e = mid-1; 

            mid = s + (e-s)/2;       
        }
        return ans;
        
    }
};
