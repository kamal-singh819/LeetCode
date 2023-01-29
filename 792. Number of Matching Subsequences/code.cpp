class Solution {
    private:
    int checkSubsequence(string s, string x){
        int i = x.length()-1;
        int j = s.length()-1;
        while(i >= 0 && j >= 0){
            if(x[i] == s[j]){
                i--;
                j--;
            }
            else
                j--;
        }
        if(i == -1) // is x is traversed completely---
            return 1;
        return 0;    
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string, int> mp;
        for(auto x : words){
            if(mp.count(x))
                ans += mp[x];
            else{
                mp[x] = checkSubsequence(s,x);
                ans += mp[x];
            }    
        }
        return ans;
        
    }
};
