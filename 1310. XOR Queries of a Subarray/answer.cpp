class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);

        //create prefix xor of array arr--
        for(int i=1; i<arr.size(); i++) arr[i] = arr[i-1]^arr[i];
        //prefix xor is store in arr--

        //same as we find range sum here we are finding range xor
        for(int i=0; i<n; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0) ans[i] = arr[r];
            else ans[i] = arr[r]^arr[l-1];
        }
        return ans; 
    }
};
