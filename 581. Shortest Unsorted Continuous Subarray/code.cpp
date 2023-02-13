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

////////////////////////////////////////////   Time Complexity is O(N) and S.C is (1)..............
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        //first find end--
        int mx = nums[0];
        int end = -1;
        for(int i=1; i<n; i++){
            if(mx > nums[i])
                end = i;
            else
                mx = nums[i];
        }

        //now find start--
        int mn = nums[n-1];
        int start = 0;
        for(int i=n-2; i>=0; i--){
            if(mn < nums[i])
                start = i;
            else
                mn = nums[i];
        }

        return end-start+1;  
    }
};
