class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if(m > n)
            return false;
        vector<int> fors1(26,0);
        vector<int> fors2(26,0);

        for(char ch : s1)
            fors1[ch-'a']++;
        
        //sliding window of size 'm'----------
        int i=0;
        int j=0;
        while(j < n){
            fors2[s2[j]-'a']++;

            if(j-i+1 == m){
                if(fors1 == fors2)
                    return true;
            }
            if(j-i+1 < m)
                j++;
            else{
                fors2[s2[i]-'a']--;
                i++;
                j++;
            }    
        }
        return false;
        
    }
};
