class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        int i=0;
        int j=0;
        while(j < n && i < n){
            int count = 0;
            while(j < n && chars[i] == chars[j]){
                count++;
                j++;
            }
            s += chars[i];
            if(count > 1)
                s += to_string(count);
            i = j;
        }
        chars.clear();
        for(int i=0; i<s.length(); i++)
            chars.push_back(s[i]);

        return chars.size();
    }
};
