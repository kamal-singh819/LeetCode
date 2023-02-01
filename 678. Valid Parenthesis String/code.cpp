class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int count = 0;
        stack<int> st;
        stack<int> star;
        int i = 0;
        while(i < n){
            if(s[i] == '*'){
                star.push(i);
            }
            else if(s[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty())
                    st.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;        
            } 
            i++;
        } 
        while(!st.empty() && !star.empty() && st.top() < star.top()){
            st.pop();
            star.pop();
        }

        return st.empty();      
    }
};
