class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = INT_MIN;
        int len = s.length();
        if(len == 1)
            return 1;

        int i = 0;
        while(i < len-1){
            int cnt = 1;
            while((s[i]-'a') + 1 == (s[i+1]-'a') && i<len-1){
                cnt++;
                i++;
            }
            ans = max(ans, cnt);
            i++;  
        }
        return ans;
        
    }
};
