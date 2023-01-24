class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.length() == 1)
            return s;
        string ans = "";
        for(int i=0; i<s.length(); ){
            string sub1;
            if(s.length()-ans.length() < k){
                sub1 = s.substr(i, s.length()-ans.length());
                reverse(sub1.begin(), sub1.end());
                ans += sub1;
                return ans;
            }else{
                sub1 = s.substr(i, k);
                reverse(sub1.begin(), sub1.end());
                ans += sub1;

            }
            if(s.length()-ans.length() < k){
                string sub2 = s.substr(i+k, s.length()-ans.length());
                ans += sub2;
                return ans;
            }else{
                string sub2 = s.substr(i+k, k);
                ans += sub2;
            }
            i = i+2*k;
        }
        return ans;
        
    }
};
