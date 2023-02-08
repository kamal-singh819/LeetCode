class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& nums) {
        for(auto x : nums){
            (this->nums).push_back(x);
        }
        
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++){
            ans += nums[i];
        }
        return ans;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
