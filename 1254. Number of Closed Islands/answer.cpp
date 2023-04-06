class Solution {
private:
    bool isSafe(int x, int y, int &m, int &n, vector<vector<int>>& grid, bool &flag){
        if(x >= m || y >= n || x < 0 || y < 0){
            flag = false;
            return false;
        }
        else if(grid[x][y] == 0) return true;
        return false;
    }
    void dfs(int i, int j, int &m, int &n, vector<vector<int>>& grid, bool &flag){
        grid[i][j] = 2;
        //left
        if(isSafe(i-1, j, m, n, grid, flag))
            dfs(i-1, j, m, n, grid, flag);
        //right
        if(isSafe(i+1, j, m, n, grid,flag))
            dfs(i+1, j, m, n, grid, flag);
        //down
        if(isSafe(i, j+1, m, n, grid, flag))
            dfs(i, j+1, m, n, grid, flag);
        //up
        if(isSafe(i, j-1, m, n, grid, flag))
            dfs(i, j-1, m, n, grid, flag);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        bool flag = true;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    dfs(i, j, m, n, grid, flag);
                    if(flag != false) ans++;
                    flag = true;
                }
            }
        }
        return ans;   
    }
};
