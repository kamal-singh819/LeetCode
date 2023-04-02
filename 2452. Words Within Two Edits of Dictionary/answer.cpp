class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0; i<queries.size(); i++){
            string str1 = queries[i];
            for(int j=0; j<dictionary.size(); j++){
                string str2 = dictionary[j]; 
                int x = 0, y=0;
                int cnt = 0;
                while(x < str1.length() && y < str2.length()){
                    if(str1[x] != str2[y])
                        cnt++;
                    x++;
                    y++;
                }
                if(cnt <= 2){
                    ans.push_back(str1);
                    break;
                }
            }
        }
        return ans;   
    }
};
