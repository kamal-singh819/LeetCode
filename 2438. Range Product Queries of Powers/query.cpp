class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int M = 1e9 + 7;
        //first find power of 2 whose sum is equal to n..
        vector<long long> powers;
        vector<long long> powersTwo;
        while(n > 0){
            powers.push_back((int)n%2);
            n /= 2;
        }
        for(int i=0; i<powers.size(); i++){
            if(powers[i] == 1){
                powersTwo.push_back(pow(2, i));
            }
        }
        int m = queries.size();
        vector<int> ans(m); 
        int ind = 0;
        for(auto q : queries){
            long long mul = 1;
            for(int i=q[0]; i<=q[1]; i++) mul = (mul * powersTwo[i]%M);
            ans[ind++] = (int)mul;
        }
        return ans;
    }
};
