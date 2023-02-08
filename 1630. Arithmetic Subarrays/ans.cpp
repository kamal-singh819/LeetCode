class Solution {
    bool isArithmetic(vector<int> arr){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=1; i<n-1; i++){
            if(arr[i+1]-arr[i] != arr[1]-arr[0])
                return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = nums.size();
        int m = l.size();
        for(int i=0; i<m; i++){
            vector<int> sub(nums.begin() + l[i], nums.begin() + r[i]+1);
            bool p = isArithmetic(sub);
            ans.push_back(p);
        }

        return ans;  
    }
};

//vector<int> b(a.begin() + 1, a.begin() + 4);
