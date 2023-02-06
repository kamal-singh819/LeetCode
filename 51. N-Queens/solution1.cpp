class Solution {
private:
    bool isSafe(int x, int y, vector<vector<char>> &board, int n){
        //check in left side for the same row, no need to check in right side coz we are palcing from left to right
        int i=x;
        int j=y;
        while(j>=0){
            if(board[i][j] == 'Q')
                return false;
            j--;    
        }

        //no need to check column coz we are placing only one queen in a column

        //now check for diagonal---
        i=x;
        j=y;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i=x;
        j=y;
        while(i<n && j>=0){
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

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
                solve(col+1, board, n, ans); //call for next column
                board[row][col] = '.'; //backTracking----------
            }
        }
    }
public:
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
