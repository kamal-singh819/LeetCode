class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 1) return duration;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i == n-1) ans += duration;
            else{
                int x = timeSeries[i]+duration;
                if(x <= timeSeries[i+1]) ans += duration;
                else ans += (timeSeries[i+1] - timeSeries[i]);
            }
        }
        return ans; 
    }
};
