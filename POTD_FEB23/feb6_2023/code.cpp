//Inplace solution---------------------------

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //approach is, we have to store two numbers at one place--
        int first = 0;
        int second = n;
        int maxx = 10000; //because limit of integer is 1000 here
        for(int i=0; i<2*n; i++){
            if(i%2 == 0)
                nums[i] = (nums[first++]%maxx)*maxx + nums[i];
            else
                nums[i] = (nums[second++]%maxx)*maxx + nums[i];
        }
        //if we calculate - nums[i]%maxx means what is on ith position but nums[i]/maxx means what should be placed on ith position after suffling-------

        for(int i=0; i<2*n; i++)
            nums[i] = nums[i]/maxx;
        
        return nums;   
    }
};

//extra space-----------

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[n+i]);
        }
        return ans;   
    }
};
