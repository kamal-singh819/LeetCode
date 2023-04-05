class Solution {
    private:
    bool canDistribute(vector<int> &candies, long long k, long long x){
        vector<long long> arr(candies.begin(), candies.end());
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < x) return false;
            else{
                k -= arr[i]/x;
                if(k <= 0) return true;
            }
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        //we can use Linera search from 1 to 10^7 // But it will give TLE
        //Use Bianry Search
        sort(candies.begin(), candies.end(), greater<>());
        long long start = 1;
        long long end = candies[0];
        long long mid = (start + end)/2;
        while(start <= end){
            //cout<<mid<<" ";
            if(canDistribute(candies, k, mid)) start = mid+1;
            else end = mid-1;
            mid = (start + end)/2;
        }
        return end; 
    }
};
