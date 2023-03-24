class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> vec(n);
        for(int i=0; i<n; i++) vec[i] = {growTime[i], plantTime[i]};

        sort(vec.begin(), vec.end(), greater<pair<int, int>>());

        int ans = INT_MIN;
        int plant = 0;
        for(auto x : vec){
            plant = plant + x.second;
            int grow = plant + x.first;
            ans = max(ans, grow);
        }
        return ans; 
    }
};
