// T.C = O(NlogN)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        if(nums == arr)
            return 0;

        int i = 0;
        int j = arr.size()-1;

        while(i <= j){
            if(arr[i] == nums[i] || arr[j] == nums[j]){
                if(arr[i] == nums[i])
                    i++;
                if(arr[j] == nums[j])
                    j--;
            }
            else
                break;
            
        }

        return j-i+1;
        
    }
};
