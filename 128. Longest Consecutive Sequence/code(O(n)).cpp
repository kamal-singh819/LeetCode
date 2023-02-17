//O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        int ans = INT_MIN;
        for(int num : nums){
            if(st.count(num-1) == 0){
                int current = num;
                int cnt = 1;
                while(st.count(current+1)){
                    cnt++;
                    current++;
                }

                ans = max(ans, cnt);
            }
        }
        return ans;
        
    }
};
