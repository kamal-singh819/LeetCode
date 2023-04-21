class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int index = 1; //for temp
        int prev = nums[0];
        int i = 1; //for nums
        int cnt = 0;
        while(i < n){
            if(index%2 == 0){
                if(i == n-1) cnt++;
                prev = nums[i];
                index++;
            }
            else{
                while(i < n && prev == nums[i]){
                    i++;
                    if(i == n) cnt++;
                    cnt++;
                }
                index++;
            }
            i++;
        }
        return cnt;
    }
};
