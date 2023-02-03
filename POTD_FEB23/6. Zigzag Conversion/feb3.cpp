class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vec(numRows, "");
        int i=0;
        int n = s.length();
        while(i < n){
            //for column filling
            for(int j=0; j<numRows && i<n; j++){
                vec[j].push_back(s[i]);
                i++;
            }
            
            //for diagonal filling
            for(int j=numRows-2; j>=1 && i<n; j--){
                vec[j].push_back(s[i]);
                i++;
            }
        }

        string ans = "";
        for(auto x : vec){
            ans += x;
        }
        return ans;
        
    }
};
