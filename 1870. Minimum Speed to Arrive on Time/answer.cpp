class Solution {
private:
    bool isPossibleToReachOnTime(int speed, double hour, vector<int> &dist, int &n){
        double timeReq = 0.0;
        for(int i=0; i<n; i++){
            double time = 0.0;
            if(i != n-1) time = (double)ceil(dist[i]/(double)speed);
            else time = dist[i]/(double)speed;

            timeReq += time;
            if(timeReq > hour) return false;
        }
        return timeReq <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        //we can linearly search for speed 1,2,3,4,.........etc (km/h)
        //But it will gice TLE
        //So use Binary Search
        int n = dist.size();
        int minSpeed = 1; //min speed is 1 km/h
        int maxSpeed = 1e7; //100000 km/h
        int ans = -1;
        while(minSpeed <= maxSpeed){
            int mid = minSpeed + (maxSpeed-minSpeed)/2;
            if(isPossibleToReachOnTime(mid, hour, dist, n)){
                ans = mid;
                maxSpeed = mid-1;
            }
            else minSpeed = mid+1;
        }
        return ans; 
    }
};
