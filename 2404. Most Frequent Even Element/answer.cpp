class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 0)
                mp[nums[i]]++;
            else
                continue;    
        }
        int ans = INT_MAX;
        int val = -1;
        for(auto x : mp){
            if(val == x.second){
                ans = min(ans, x.first);
            } 
            else{
                if(val < x.second){
                    ans = x.first;
                    val = x.second;
                }
                else if(val > x.second){
                    ans = ans;
                    val = val;
                }
            }
            
        }
        return ans == INT_MAX ? -1 : ans;   
    }
};
