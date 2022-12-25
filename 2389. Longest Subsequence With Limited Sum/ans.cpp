class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end()); //sort the nums vector
        vector<int> ans(m);
        for(int k=0; k<m; k++){
            int qri = queries[k];
            int s = 0; //represent sum of subsequence 
            int x = 0; //represent maximum size of subsequence
            for(int i=0; i<n; i++){
                s += nums[i];
                if(s <= qri && i<n){
                    x++;
                }
                else{
                    break;
                }
            }
            ans[k] = x; 
        }
        return ans;
        
    }
};
