class Solution {
public:
    unordered_map<int, int> mp;
    bool compare(string s1, string s2){
        int m = s1.length();
        int n = s2.length();
        int j=0;
        while(j < m && j < n){
            if(s1[j] == s2[j])
                j++;
            else if(mp[s1[j]-'a'] > mp[s2[j]-'a'])
                return true;
            else
                return false;        
        }
        if(m < n)
            return false;
        return true;    
    }

    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=0; i<order.length(); i++){
            mp[order[i]-'a'] = i;
        }
        for(int i=1; i<words.size(); i++){
            if(!compare(words[i], words[i-1]))
                return false;
        } 
        return true;
    }

};
