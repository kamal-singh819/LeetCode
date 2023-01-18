class Solution {
public:
    void dfs(int i , int j , int &area, vector<vector<int>>& grid){
        if(!(i >= 0 && i <grid.size() && j >=0 && j<grid[0].size() && grid[i][j] == 1 ))
            return;
        area++; // increase area by 1
        grid[i][j] = 0; 
        dfs(i-1 , j , area , grid); 
        dfs(i , j+1 , area, grid);  
        dfs(i+1, j , area, grid);  
        dfs(i, j-1, area , grid);  
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int area = 0;

        for(int i = 0 ; i< grid.size() ; i++){
            for(int j = 0; j<grid[0].size() ; j++){
                if(grid[i][j] == 1){ 
                    dfs(i , j , area, grid);
                    max_area = max(max_area, area);
                    area = 0;
                }
            }
        }
        return max_area;
    }
};
