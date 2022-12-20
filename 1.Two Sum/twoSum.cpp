//// Time Complexity is - O(N)  //////

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int temp = target - nums[i];
            if(mp.count(temp)){
                ans.push_back(i);
                ans.push_back(mp[temp]);
                return ans;
            }
            mp[nums[i]] = i;
        }    
        return ans;    
    }
};

////Time Complexity is O(N^2)   ////

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
                if((nums[i] + nums[j]) == target){
                ans.push_back(i);
                ans.push_back(j);
            }
           }
        }
        return ans;
        
    }
};
