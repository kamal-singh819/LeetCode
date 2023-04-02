class Solution {
private:
    int binarySearch(vector<pair<int, int>> &pair,int val, int x, int y){
        int mid = x + (y-x)/2;
        while(x <= y){
            if(val < pair[mid].first) y = mid-1;
            else x = mid+1;

            mid = x + (y-x)/2;
        }
        return y;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> pair(n);
        for(int i=0; i<n; i++) pair[i] = {difficulty[i], profit[i]};

        sort(pair.begin(), pair.end());
        //update the values with maximum profit
        for(int i=1; i<n; i++) pair[i].second = max(pair[i].second, pair[i-1].second);

        int ans = 0;
        //now use Binary Search on pair
        for(int i=0; i<worker.size(); i++){
            int ind = binarySearch(pair, worker[i], 0, n-1);
            if(ind != -1) ans += pair[ind].second;
        }
        return ans; 
    }
};
