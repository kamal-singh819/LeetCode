class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> st;
        for(int i=0; i<nums.size(); i++) st.insert((long long)nums[i]);

        int ans = -1; 
        int i = 0;
        while(i < nums.size()){
            int count = 0;
            long long num = (long long)nums[i];
            while(st.count(num)){
                count++;
                num = pow(num, 2);
            }
            //cout<<count<<" ";
            ans = max(ans, count);
            i++;
        }
        return ans == 1 ? -1 : ans; 
    }
};

////////////////////////////////////////            Dynamic Programming

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        unordered_map<long long, long long> mp;
        for(int i=n-1; i>=0; i--){
            long long curr = (long long) nums[i];
            long long sq = curr*curr;

            if(mp.count(sq)) mp[curr] = mp[sq]+1;
            else mp[curr] = 0;

            ans = max(ans, mp[curr]); 
        }
        return ans != 0 ? (int)ans+1 : -1;  
    }
};
