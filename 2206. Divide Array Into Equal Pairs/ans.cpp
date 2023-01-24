class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2 != 0)
            return false;
        
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;

        for(auto y : mp){
            if(y.second % 2 != 0)
                return false;
        }  
        return true;  
        
    }
};
