

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPosition = nums.size()-1;
        int n = lastPosition;

        for(int i=n-1; i>=0; i--){
            if(i+nums[i] >= lastPosition){
                lastPosition = i;
            }
        }
        return lastPosition == 0;
        
    }
};
