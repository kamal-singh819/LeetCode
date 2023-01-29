class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans;
        int n = t.length();
        int m = s.length();
        int i=0; //for t
        int j=0; //for s
        while(i<n && j<m){
            if(t[i] == s[j]){
                i++;
                j++;
            }
            else
                j++;
        }
        if(j == m && i == n)
            return 0;

        return t.length()-i;    
        
    }
};
