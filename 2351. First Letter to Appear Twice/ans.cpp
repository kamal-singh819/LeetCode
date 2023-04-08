class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        for(char ch : s){
            if(st.count(ch)) return ch;
            st.insert(ch);
        }
        return 'a';
    }
};
