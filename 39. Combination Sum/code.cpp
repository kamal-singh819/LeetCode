class Solution {
private:
    void fun(vector<int> &arr, int target, vector<int> &out, vector<vector<int>> &ans, int i){
        if(i == arr.size()){
            if(target == 0) ans.push_back(out);
            return;
        }
        
        //if we select current element
        if(arr[i] <= target){
            out.push_back(arr[i]);
            fun(arr, target-arr[i], out, ans, i); //stay at the same index cozz same number can be selected unlimited times
            out.pop_back(); //backTrack
        }
        //if we don't select current element
        fun(arr, target, out, ans, i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> out;
        fun(candidates, target, out, ans, 0);
        return ans;   
    }
};
