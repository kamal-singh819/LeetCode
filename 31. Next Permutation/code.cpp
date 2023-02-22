class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(), nums.end());  //only one code line to calculate answer 
        int n = nums.size();
        int s, l;

        //traverse array from end to find the index where nums[i] < nums[i+1]
        for(s=n-2; s>=0; s--){
            if(nums[s] < nums[s+1]){
                break;
            }
        }

        //if nums is already sorted in decreasing order then s = -1, so just reverse the nums only
        if(s < 0){
            reverse(nums.begin(), nums.end());
        }
        //again traverse from last and find first index where nums[i] > nums[s]
        else{
            for(l=n-1; l>= 0; l--){
                if(nums[l] > nums[s]){
                    break;
                }
            }
            //then swap nums[s] and nums[l]
            swap(nums[s], nums[l]);
            //and reverse the array from s+1 to end of the array
            reverse(nums.begin()+s+1, nums.end());
        }
    }
};
