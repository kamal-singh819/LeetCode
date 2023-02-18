class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1)
            return s.length();
        unordered_map<char, bool> mp;
        int i=0;
        int j=0;
        int ans = INT_MIN;
        while(j < s.length()){
            char ch = s[j];
            if(mp.count(ch) != 1){
                mp[ch] = true;
                j++;
                if(j == s.length())
                    return max(ans, j-i);
            }
            else{
                ans = max(ans, j-i);
                mp.erase(s[i]);
                i++;
            }
        }
        return ans;
        
    }
};
