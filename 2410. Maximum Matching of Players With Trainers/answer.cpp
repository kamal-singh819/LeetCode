class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int p = players.size();
        int t = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int ans = 0;
        int i=0; //for player array
        int j=0; //for trainer array
        while(i < p && j < t){
            if(players[i] <= trainers[j]){
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};
