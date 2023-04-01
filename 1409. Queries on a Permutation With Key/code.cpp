class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> ans(n);

        vector<int> mm(m);
        for(int i=1; i<=m; i++) mm[i-1] = i;
        for(int i=0; i<n; i++){
            int ind;
            //find index of queries[i]
            for(int j=0; j<m; j++){
                if(mm[j] == queries[i]){
                    ind = j;
                    break;
                }
            }
            ans[i] = ind;
            for(int j=ind; j>0; j--) mm[j] = mm[j-1];
            mm[0] = queries[i];
        } 
        return ans;
    }
};
