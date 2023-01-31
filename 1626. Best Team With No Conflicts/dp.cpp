class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> vp;
        for(int i=0;i<n; i++){
            vp.push_back(make_pair(ages[i], scores[i]));
        }
        sort(vp.begin(), vp.end());
        int ans = 0;
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            dp[i] = vp[i].second;
            for(int j=0; j<i; j++){
                if(vp[j].second <= vp[i].second)
                    dp[i] = max(dp[i], dp[j]+vp[i].second);
            }

            ans = max(ans, dp[i]);
        }
        return ans;
        
    }
};
