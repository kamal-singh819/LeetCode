class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n <= 1)
            return n; 
        if(s[0] != s[n-1])
            return s.length();

        int i = 0;
        int j = n-1; 
        while(i <= j){
            if(i == j)
                return 1;
            if(s[i] != s[j])
                return j-i+1;

            else if(s[i] == s[j]){
                while(s[i] == s[i+1]){
                    i++;
                    if(i==j)
                        return 0;
                }
                while(s[j] == s[j-1]){
                    j--;
                    if(j == i)
                        return 0;
                }          
                i++; j--;      
            }    
        } 
        return 0;       
    }
};
