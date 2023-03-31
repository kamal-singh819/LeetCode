class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string> > mp;
        for(auto str : words){
            int n = str.length();
            string num = "";
            for(int i=0; i<n-1; i++){
                num += to_string((str[i+1]-'a')-(str[i]-'a'));
                num += "_";
            }
            mp[num].push_back(str);
        }
        for(auto x : mp){
            if(x.second.size() == 1) return x.second[0];
        }
        return "";  
    }
};
