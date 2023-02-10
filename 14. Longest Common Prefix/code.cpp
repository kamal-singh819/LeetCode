class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string first = strs[0];
        int x = first.length(); //we will store the length of common prefix
        for(int i=1; i<n; i++){
            int j = 0;
            while(first[j] == strs[i][j] && j < strs[i].length() && j < first.length())
                j++;
            
            x = min(x, j);
        }

        return first.substr(0, x);

    }
};
