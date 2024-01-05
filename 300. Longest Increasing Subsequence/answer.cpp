////   BINARY SEARCH SOLUTION - ONLY APPLICABLE WHEN ASKED ONLY FOR LENGTH OF LIS
////   TIME COMPLEXITY : O(nlogn) and Space Complexity : O(n)
////   C++ CODE
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};


/////   DYNAMIC PROGRAMMING SOLUTION   
//// TIME COMPLEXITY : O(n^2)
////    JAVA CODE
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] LIS = new int[n];
        for(int i=0; i<n; i++) LIS[i] = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    //below if condition is necessary, dry run Test case-2
                    if(LIS[j] >= LIS[i]) LIS[i] = 1+LIS[j];
                }
            }
        }
        int ans = 0;
        for(int x : LIS) ans = Math.max(ans, x);
        return ans;
    }
}
