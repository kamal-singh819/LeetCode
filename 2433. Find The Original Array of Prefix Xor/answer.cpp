class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        if(n <= 1) return pref;
        vector<int> ans(n);
        ans[0] = pref[0];

        int a = ans[0];
        for(int i=1; i<n; i++)
            ans[i] = pref[i]^pref[i-1];
        return ans;
        
    }
};
