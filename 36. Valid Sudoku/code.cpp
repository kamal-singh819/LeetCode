class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    string row = "row"+to_string(i)+board[i][j];
                    string col = "col"+to_string(j)+board[i][j];
                    string box = "box"+to_string((i/3)*3 + j/3) + board[i][j];

                    if(st.find(row) == st.end() && st.find(col) == st.end() && st.find(box) == st.end()){
                        st.insert(row);
                        st.insert(col);
                        st.insert(box);
                    }
                    else
                        return false;
                }
            }
        }
        return true;
        
    }
};
