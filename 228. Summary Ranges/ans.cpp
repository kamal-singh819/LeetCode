class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};

        vector<string> ans;
        for(int i=0; i<n; ){
            string temp = "";
            temp += to_string(nums[i]);
            int k = i; //track of index of first number of an interval
            int j=i+1;
            while(j<n && nums[i] == nums[j]-1){
                i++;
                j++;
            }
            if(j == k+1){
                ans.push_back(temp);
            }
            else{
                temp += "->";
                temp += to_string(nums[i]);
                ans.push_back(temp);
            }
            i = j;
        }
        return ans;
        
    }
};
