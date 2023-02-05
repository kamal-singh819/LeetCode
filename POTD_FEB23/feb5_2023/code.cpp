class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int m = s.length();
        int n = p.length();
        if(m < n)
            return ans;
        vector<int> fors(26,0);
        vector<int> forp(26,0); //for string p

        for(auto ch : p)
             forp[ch-'a']++;

        int i=0;
        int j=0;

        while(j < m){
            fors[s[j]-'a']++;
            if(j-i+1 == n){ //if window size matched---
                if(fors == forp)
                    ans.push_back(i);   
            }
            if(j-i+1 < n) //window is less than n, increase the size by j forward---
                j++;
            else{
                fors[s[i]-'a']--; //in case of window size exceeding, remove ith and move i & j by one
                i++;
                j++;
            }    
        } 
        return ans;   

    }
};
