class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 != 0) return {};
        int i=0;
        vector<int> ans;
        while(i < n){
            int freq = nums[i];
            int val = nums[i + 1];
            while(freq--) ans.push_back(val);
            i = i+2;
        }
        return ans;
        
    }
};
