class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n == 1){
            s = "1";
            return "1";
        }

        for(int i=1; i<n; i++){ 
            string res = "";
            int m = s.length(); //length of s;;;
            int j = 0;
            int k = j;
            while(j<m && k<m){
                while(s[j] == s[k])
                    k++;
                res += to_string(k-j);
                res += s[j];

                j = k;
            }
            s = res; //as every string is dependent on previous string, we have to store previous string finding for next string 
        }
        return s;
        
    }
};
