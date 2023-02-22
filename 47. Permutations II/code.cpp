class Solution {
public:
    void recursive(int index, vector<int> nums, set<vector<int>> &temp){
        if(index >= nums.size()){
            temp.insert(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]); 
            recursive(index+1, nums, temp);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> temp;
        int index = 0;
        recursive(index, nums, temp); 
        for(auto vec : temp){
            ans.push_back(vec);
        }
        return ans;
    }
};
