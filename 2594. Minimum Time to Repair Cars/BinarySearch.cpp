/////////////////////////    Time Complexity   :    O(n*log(end)) where n=ranks.size() and end = 1e14...

class Solution {
private:
    bool isPossible(long long t, vector<int> &ranks, int cars){
        long long totalRequired = 0;
        for(int r : ranks){
            long long canRepair = sqrt(t/r);
            totalRequired += canRepair;
        }
        return totalRequired >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1;
        long long end = 1e14; //As r*n^2 = 100*(10^6 * 10^6) take max value of r and n to compute end
        while(start < end){
            long long mid = start + (end-start)/2;
            if(isPossible(mid, ranks, cars)) end = mid;
            else start = mid+1;
        }
        return start;    
    }
};
