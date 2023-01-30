class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        int count = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')' && st.empty()) //if reading character is ')' and stack is empty, add it to ans
                count++;
            else if(s[i] == ')' && !st.empty()){
                st.pop();
            }       
        }
        return count+st.size();
        
    }
};
