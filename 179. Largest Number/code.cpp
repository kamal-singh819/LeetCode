class Solution {
public:
    static bool comp(string &a, string &b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return to_string(nums[0]);

        vector<string> vec(n);
        for(int i=0; i<nums.size(); i++){
            vec[i] = to_string(nums[i]);
        }
        sort(vec.begin(), vec.end(), comp);
        // for(auto x : vec)
        //     cout<<x<<" ";

        string ans = "";
        for(int i=0; i<n; i++){
            ans += vec[i];
        }
        int i=0;
        while(i<ans.size()-1 && ans[i]=='0')
            i++;
        return ans.substr(i, ans.size());
    }
};
