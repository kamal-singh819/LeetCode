class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]-i]++;
        }

        long long ans = 0;
        for(auto x : mp){
            int c = x.second;
            while(c > 0){
                ans += (n-c);
                n--;
                c--;
                //if(c == 0) break;
            }
        }
        return ans;   
    }
};
