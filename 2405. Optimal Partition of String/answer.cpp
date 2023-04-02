class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        unordered_set<char> st;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(st.count(s[i])){
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans+1; //why +1, because when i is reaching at last index, 
                      //it is not considering last substring 
    }
};
