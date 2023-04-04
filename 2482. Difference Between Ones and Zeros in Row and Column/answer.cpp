class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowSum(m, 0); //stores sum of each and every row
        vector<int> colSum(n, 0); //stores sum of each and every col
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }
        //now sum is stored--
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = 2*(rowSum[i] + colSum[j]) - (n+m);
            }
        }
        return grid;    
    }
};
//              no. of one's
//line - 19. (rowSum[i]+colSum[j]) - ((n+m) - (rowSum[i]+colSum[j]))
