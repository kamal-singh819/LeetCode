class Solution {
private: vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(0));
    }
    
    int pick(int target) {
        int n = nums.size();
        int random = rand()%n; //take a random index
        while(nums[random] != target){ //check if nums[random] == target then return random otherwise search other random index
            random = rand()%n;
        }
        return random;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
