//////////////Using STACK       ////////////////
class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length() == 1) return s;
        string ans = "";
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(st.empty() || st.top() != s[i]) st.push(s[i]);

            else if(!st.empty() && st.top() == s[i]) st.pop();
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;    
    }
};

//without STACK

class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length() == 1) return s;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(ans.length() == 0) ans.push_back(s[i]);
            else if(ans.length() != 0 && ans[ans.length()-1] == s[i]) ans.pop_back();
            else if(ans.length() != 0 && ans[ans.length()-1] != s[i]) ans.push_back(s[i]);
        }
        return ans;
        
    }
};
