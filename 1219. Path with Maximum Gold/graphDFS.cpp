class Solution {
    private:
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n){
        int gold = 0;
        int temp = 0; //for backtrack---
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0)
            return 0;
        temp = grid[i][j];
        grid[i][j] = 0;

        gold = max(gold, dfs(grid, i+1, j, m, n));
        gold = max(gold, dfs(grid, i, j+1, m, n));
        gold = max(gold, dfs(grid, i-1, j, m, n));
        gold = max(gold, dfs(grid, i, j-1, m, n));
        grid[i][j] = temp; //backtrack---

        return gold+temp;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }
        return ans;   
    }
};
