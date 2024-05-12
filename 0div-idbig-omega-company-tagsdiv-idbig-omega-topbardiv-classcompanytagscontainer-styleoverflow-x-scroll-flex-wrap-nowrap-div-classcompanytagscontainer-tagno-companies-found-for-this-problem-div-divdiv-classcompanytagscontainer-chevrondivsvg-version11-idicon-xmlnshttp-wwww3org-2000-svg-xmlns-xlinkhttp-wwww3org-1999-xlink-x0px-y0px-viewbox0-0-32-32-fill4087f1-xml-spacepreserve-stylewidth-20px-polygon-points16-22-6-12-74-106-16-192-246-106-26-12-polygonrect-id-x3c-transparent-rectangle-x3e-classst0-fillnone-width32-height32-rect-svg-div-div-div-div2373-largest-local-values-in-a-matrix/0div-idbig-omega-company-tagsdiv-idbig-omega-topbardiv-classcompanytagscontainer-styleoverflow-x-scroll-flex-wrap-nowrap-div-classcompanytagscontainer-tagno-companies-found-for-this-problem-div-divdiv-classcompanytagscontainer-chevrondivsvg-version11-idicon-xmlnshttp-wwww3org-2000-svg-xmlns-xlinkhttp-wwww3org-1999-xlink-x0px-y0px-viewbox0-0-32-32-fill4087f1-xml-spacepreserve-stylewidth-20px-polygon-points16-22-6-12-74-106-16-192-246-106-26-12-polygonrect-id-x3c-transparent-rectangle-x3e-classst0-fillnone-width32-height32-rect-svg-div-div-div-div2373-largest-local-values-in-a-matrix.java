class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] ans = new int[n-2][n-2];
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                int mx = 0;
                for (int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        mx = Math.max(mx, grid[i+k][j+l]);
                    }
                }
                ans[i][j] = mx;
            }
        }
        return ans;
    }
}