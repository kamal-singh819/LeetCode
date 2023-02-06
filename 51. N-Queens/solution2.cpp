class Solution {
public:
    unordered_map<int, bool> mpRows;
    unordered_map<int, bool> mpDiaLow;
    unordered_map<int, bool> mpDiaUpr;

    bool isSafe(int x, int y, vector<vector<char>> &board, int n){
        if(mpRows[x] == true || mpDiaLow[x+y] == true || mpDiaUpr[(n-1)+(y-x)] == true)
            return false;  
        return true;      
    }

    void getAnswer(vector<vector<char>> &board, vector<vector<string>> &ans, int n){
        vector<string> vstr;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<n; j++){
                temp += board[i][j];
            }
            vstr.push_back(temp);
        }
        ans.push_back(vstr);
    }
    void solve(int col, vector<vector<char>> &board, int n, vector<vector<string>> &ans){
        if(col == n){
            getAnswer(board, ans, n);
            return;
        }

        //for each row of column col----
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q'; //queen placed
                mpRows[row] = true; //map for keeping track of placing Queen in row
                mpDiaLow[row+col] = true; //in lower diagonal (only left side)
                mpDiaUpr[(n-1)+(col-row)] = true; //in upper diagonal(only left side)
                solve(col+1, board, n, ans); //call for next column
              //backtracking--------------------------------------------------
                board[row][col] = '.';
                mpRows[row] = false;
                mpDiaLow[row+col] = false;
                mpDiaUpr[(n-1)+(col-row)] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n == 1)
            return {{"Q"}};
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0; //start from column 0
        solve(col, board, n, ans);
        return ans;   
    }
};
