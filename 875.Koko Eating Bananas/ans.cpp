typedef long long int ll;
class Solution {
private:
    bool isPossibleToEat(ll mid, vector<int> &piles, int h, int &n){
        ll H = 0;
        for(int i=0; i<n; i++){
            int hours = ceil(piles[i] / (double)mid);
            H += hours;
        }
        return H <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //we can try for all k linearly at k=1,2,3,4,.....etc
        //But Time Complexity will be O(N*piles[i]) in the Worst case 10^13 operation
        //and It gives TLE

        //so try Binary Search and find K
        ll start = 1; //min value of k may be 1
        ll end = 1e9;
        int n = piles.size();
        int ans = -1;
        while(start <= end){
            ll mid = start + (end - start) / 2;
            if(isPossibleToEat(mid, piles, h, n)){
                ans = (int)mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};
