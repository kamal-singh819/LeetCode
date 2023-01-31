class Solution {
public:
    void printSubsets(vector<int> &nums, int i, vector<int> &output, set<vector<int>> &res){
        if(i == nums.size()){
            //sort(output.begin(), output.end());
            res.insert(output);
            return;
        }
        printSubsets(nums, i+1, output, res);
        output.push_back(nums[i]);
        printSubsets(nums, i+1, output, res);
        output.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> output;
        int start = 0;
        sort(nums.begin(), nums.end()); //when we have more duplicates, we will sort the array then pass to function-----------

        printSubsets(nums, start, output, res);

        vector<vector<int>> ans(res.begin(), res.end());

        return ans;
        
    }
};
