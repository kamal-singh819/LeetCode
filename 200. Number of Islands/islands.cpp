class Solution {
private:
  //this function will make sure the move is valid or not
    bool isValidMove(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1')
            return true;
        return false;    
    }
    void dfsGrid(int i, int j, int n, int m, vector<vector<char>>& grid){
        grid[i][j] = '2'; //mark as visited

        if(isValidMove(i+1, j, n, m, grid)){
            dfsGrid(i+1, j, n, m, grid);
        }
        if(isValidMove(i-1, j, n, m, grid)){
            dfsGrid(i-1, j, n, m, grid);
        }
        if(isValidMove(i, j+1, n, m, grid)){
            dfsGrid(i, j+1, n, m, grid);
        }
        if(isValidMove(i, j-1, n, m, grid)){
            dfsGrid(i, j-1, n, m, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfsGrid(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
};
