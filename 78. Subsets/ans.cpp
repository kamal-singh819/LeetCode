class Solution {
private:
    void solve(vector<int> nums, int index, vector<vector<int> > &ans, vector<int> &output){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        solve(nums, index+1, ans, output); //left call
        output.push_back(nums[index]);  //push
        solve(nums, index+1, ans, output);  //right call
        output.pop_back(); //exclude the previous included element
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        
        solve(nums, index, ans, output);
        return ans;
    }
};
