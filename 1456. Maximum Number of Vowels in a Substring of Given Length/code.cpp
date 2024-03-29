class Solution {
public:
    int maxVowels(string s, int k) {
        if(k > s.length())
            return 0;
        int i=0,j=0;
        int n = s.length();
        int cnt = 0;
        int ans = INT_MIN;
        while(j < n){
            if(j-i+1 < k){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    cnt++;
                
                j++;
            }
            else if(j-i+1 == k){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    cnt++;
                ans = max(ans, cnt);
                j++;

            }
            else{
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    cnt--;
                
                i++;
            }
        }
        return ans;
        
    }
};


/////////////////////////////////////////////  USE hashMap   //////////////////////////////////////

class Solution {
public:
    int maxVowels(string s, int k) {
        if(k > s.length())
            return 0;
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int i=0,j=0;
        int n = s.length();
        int cnt = 0;
        int ans = INT_MIN;
        while(j < n){
            if(j-i+1 < k){
                if(st.count(s[j]) > 0)
                    cnt++;
                
                j++;
            }
            else if(j-i+1 == k){
                if(st.count(s[j]) > 0)
                    cnt++;
                ans = max(ans, cnt);
                j++;

            }
            else{
                if(st.count(s[i]) > 0)
                    cnt--;
                
                i++;
            }
        }
        return ans;
        
    }
};
