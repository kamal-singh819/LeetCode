class Solution {
private:
    bool isPossibleToPutBalls(int force, int &m, vector<int> &pos){
        int balls = 1;
        int lastPos = pos[0];
        for(int i=0; i<pos.size(); i++){
            if(abs(pos[i] - lastPos) >= force){
                balls++;
                if(balls == m) return true;
                lastPos = pos[i];
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        //Same as Agressive cows Problem (GFG)
        //check for each force: 1,2,3,4,................ BUT IT GIVES TLE
        //so USE Binary Seach
        int n = position.size();
        sort(position.begin(), position.end());
        int minForce = 1;
        int maxForce = position[n-1];
        int ans = -1;
        while(minForce <= maxForce){
            int mid = minForce + (maxForce - minForce)/2;
            if(isPossibleToPutBalls(mid, m, position)){
                cout<<mid<<" ";
                ans = mid;
                minForce = mid + 1;
            }
            else maxForce = mid - 1;
        }
        return ans;   
    }
};
