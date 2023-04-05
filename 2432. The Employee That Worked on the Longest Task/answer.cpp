class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans;
        int prevBest = 0;
        int startTime = 0;
        int i=0;
        while(i < logs.size()){
            if(prevBest < logs[i][1]-startTime){
                prevBest = logs[i][1]-startTime;
                ans = logs[i][0];
            }
            else if(prevBest == logs[i][1]-startTime){
                ans = min(ans, logs[i][0]);
            }
            startTime = logs[i][1];
            i++;
        }
        return ans;
    }
};
