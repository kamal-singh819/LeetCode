//                                       Java Code                                         /////

class Solution {
    public int minDeletionSize(String[] strs) {
        int ans = 0;
        int strlen = strs[0].length();
        int siz = strs.length;
        for(int j=0; j<strlen; j++){
            for(int i=0; i<siz-1; i++){
                if(strs[i].charAt(j) > strs[i+1].charAt(j)){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}

//                                        Given code in C++                                /////
/*
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int siz = strs.size();
        for(int j=0; j<strs[0].length(); j++){
            for(int i=0; i<strs.size()-1; i++){
                if(strs[i][j] > strs[i+1][j]){
                    ans++;
                    break;
                }
            }
        }

        return ans;
        
    }
};
*/
