class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.length();
        string str;
        int i = 0;
        while(i < n){
            if(s[i] == ' '){
                i++;
                continue;
            }
            str.clear();
            str = "";
            while(s[i] != ' ' && i<n){
                str.push_back(s[i]);
                i++;
            }
            v.push_back(str);
        }  
        reverse(v.begin(), v.end());
        string ans = "";
        for(auto x : v){
            ans += (x + " ");
        }
        return ans.substr(0, ans.length()-1); //to remove the last space 
    }
};
