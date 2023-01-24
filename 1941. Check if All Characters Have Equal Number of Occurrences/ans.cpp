class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
      
        for(auto x : mp){
            if(mp[s[0]] != x.second)
                return false;
        }
        return true;     
    }
};
