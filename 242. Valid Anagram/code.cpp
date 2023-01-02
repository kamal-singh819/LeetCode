class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m)
            return false;

        int sarr[27] = {0};
        int tarr[27] = {0};

        for(int i=0; i<n; i++){
            sarr[s[i]-'a']++;
            tarr[t[i]-'a']++;
        } 
        for(int i=0; i<27; i++){
            //cout<<sarr[i]<<" "<<tarr[i]<<endl;
            if(sarr[i] != tarr[i])
                return false;
        }  
        return true; 
        
    }
};
