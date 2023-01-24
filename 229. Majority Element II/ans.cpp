//Use unordered_map to store the count of corresponding element

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int n = nums.size();
        for(auto x : mp){
            if(x.second > n/3)
                ans.push_back(x.first);    
        }
        return ans;
        
    }
};
