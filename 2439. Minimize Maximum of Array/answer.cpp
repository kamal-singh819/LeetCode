class Solution {
public:
    bool isPossible(long long target, vector<int> &nums, int &n){
        vector<long long> arr(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            if(arr[i] > target) return false;
            arr[i+1] -= (target-arr[i]);
        }
        return arr[n-1] <= target;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long start = 0;
        long long end = 1e9;
        //We will check at every 'num' using Binary Search(Linear Seach - TLE), Is it 
        //possible to make array elements less than or equal to 'num'
        while(start < end){
            long long mid = (start+end)/2;
            if(isPossible(mid, nums, n)) end = mid;
            else start = mid+1;
        }
        return start; //start and mid will be same at that time
    }
};
