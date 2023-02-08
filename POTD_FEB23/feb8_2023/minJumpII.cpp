link :  https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        int countJump = 0;
        int maxReach = 0; //maximum you can reach from an index---
        int last = 0;

        for(int i=0; i<n-1; i++){
            maxReach = max(maxReach, i+nums[i]);
            if(i == last){
                last = maxReach;
                countJump++;
            }
        }
        return countJump;
        
    }
};
