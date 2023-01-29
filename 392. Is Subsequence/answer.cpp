class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = s.length()-1; //last index of s
        int j = t.length()-1; //last index of t

        if(s.length() > t.length())
            return false;

        while(i>=0 && j>=0){
            if(s[i] == t[j]){
                i--;
                j--;
            }
            else
                j--;
        }
        if(j < 0 && i >= 0)
            return false;
        return true;    
        
    }
};
