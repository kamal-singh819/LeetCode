class Solution {
private:
    bool isPossibleToComplete(long long minTime, int &tts, vector<int> &time, int &n){
        long long totalTrip = 0;
        for(int i=0; i<n; i++){
            totalTrip += minTime/(long long)time[i];
            if(totalTrip >= tts) return true;
        }
        return totalTrip >= tts;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //we can linearly search for time 1,2,3,4,5.........etc but it gives TLE
        long long ans = 0;
        int n = time.size();
        long long low = 1; //min time to complete
        long long high = 1e16; //max time may be used to complete 
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(isPossibleToComplete(mid, totalTrips, time, n)){
                ans = mid;
                high = mid-1; //as we need minimum time
            }
            else low = mid+1;
        }
        return ans;  
    }
};
