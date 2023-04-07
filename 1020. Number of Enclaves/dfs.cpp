class Solution {
private:
    bool isPossible(int x, int y, int &m, int &n, vector<vector<int>> &grid, bool &flag){
        if(x < 0 || x >= m || y < 0 || y >= n){
            flag = false;
            return false;
        }else if(grid[x][y] == 1)
            return true;
        return false;
    }
    void dfs(int i, int j, int &m, int &n, vector<vector<int>> &grid, bool &flag, int &cnt){
        grid[i][j] = 0;
        //up
        if(isPossible(i-1, j, m, n, grid, flag)){
            cnt++;
            dfs(i-1, j, m, n, grid, flag, cnt);
        }
        //down
        if(isPossible(i+1, j, m, n, grid, flag)){
            cnt++;
            dfs(i+1, j, m, n, grid, flag, cnt);
        }
        //left
        if(isPossible(i, j-1, m, n, grid, flag)){
            cnt++;
            dfs(i, j-1, m, n, grid, flag, cnt);
        }
        //up
        if(isPossible(i, j+1, m, n, grid, flag)){
            cnt++;
            dfs(i, j+1, m, n, grid, flag, cnt);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        bool flag = true;
        int cnt = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, m, n, grid, flag, cnt);
                    if(flag) ans += cnt;
                    flag = true;
                    cnt = 1;
                }
            }
        }
        return ans;  
    }
};
