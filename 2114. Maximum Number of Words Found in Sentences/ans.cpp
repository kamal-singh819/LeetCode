class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            string str = sentences[i];
            int nwords = 1;
            for(int j=0; j<str.length(); j++){
                if(str[j] == ' ')
                   nwords++;
            }
            ans = max(ans, nwords);
        }

        return ans;
        
    }
};
