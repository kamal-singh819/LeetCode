//This is a simple approach and beginner friendly

class Solution {
    bool isPalindrome(string str){
        if(str.length() == 1)
            return true;
        int i = 0;
        int j = str.length()-1; 
        while(i <= j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;    
        } 
        return true;  
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            string sub = "";
            for(int j=i; j<n; j++){
                sub += s[j];
                if(isPalindrome(sub))
                    ans++;
            }
        }
        return ans;
    }
};
