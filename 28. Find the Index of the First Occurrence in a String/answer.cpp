//used sliding window approach----------------

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length(); //sliding window of m size---------
        if(n < m)
            return -1;

        string check = "";

        int i=0;
        int j=0;
        while(j < n){
            check.push_back(haystack[j]);
            if(j-i+1 == m){
                if(check == needle)
                    return i;
            }
            if(j-i+1 < m)
                j++;
            else{
                check = check.substr(1, m-1); //remove first character of check if size of check is greater than m--------
                i++;
                j++;
            }    

        }
        return -1;
        
    }
};
