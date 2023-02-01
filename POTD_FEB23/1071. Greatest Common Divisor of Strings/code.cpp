class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        if(str1+str2 == str2+str1){
            int gcdd = gcd(m, n);
            return str1.substr(0, gcdd);
        }
        return "";
        
    }
};
