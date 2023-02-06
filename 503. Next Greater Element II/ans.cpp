class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st; //monotonic stack------

        for(int i=2*n-1; i>= 0;i--){
            int x = nums[i%n];
            while(!st.empty() && st.top() <= x)
                st.pop();
            
            ans[i%n] = st.empty() ? -1 : st.top();
            st.push(x);
        }
        return ans;
        
    }
};
