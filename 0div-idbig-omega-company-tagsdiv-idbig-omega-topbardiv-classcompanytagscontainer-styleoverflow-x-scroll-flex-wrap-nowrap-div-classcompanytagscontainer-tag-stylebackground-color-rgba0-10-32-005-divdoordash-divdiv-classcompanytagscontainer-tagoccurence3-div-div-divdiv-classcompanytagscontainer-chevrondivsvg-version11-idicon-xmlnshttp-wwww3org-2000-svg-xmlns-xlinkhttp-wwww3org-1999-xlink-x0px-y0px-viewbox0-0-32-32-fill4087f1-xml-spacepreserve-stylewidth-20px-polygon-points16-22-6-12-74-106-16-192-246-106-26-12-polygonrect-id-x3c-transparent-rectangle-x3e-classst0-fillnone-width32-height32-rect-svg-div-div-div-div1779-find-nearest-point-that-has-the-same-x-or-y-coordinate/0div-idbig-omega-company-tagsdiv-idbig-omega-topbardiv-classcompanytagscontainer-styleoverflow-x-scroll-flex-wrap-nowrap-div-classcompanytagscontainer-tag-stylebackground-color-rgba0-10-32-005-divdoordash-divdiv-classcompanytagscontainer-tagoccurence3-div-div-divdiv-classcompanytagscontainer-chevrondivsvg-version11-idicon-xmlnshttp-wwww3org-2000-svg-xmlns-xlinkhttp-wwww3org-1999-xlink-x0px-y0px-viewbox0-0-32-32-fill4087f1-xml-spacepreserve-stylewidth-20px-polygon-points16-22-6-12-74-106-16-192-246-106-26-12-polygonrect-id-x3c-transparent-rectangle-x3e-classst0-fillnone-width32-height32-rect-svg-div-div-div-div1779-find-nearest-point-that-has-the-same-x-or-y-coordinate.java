class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int n = points.length;
        int dis = 100000;
        int index = -1;
        for(int i=n-1; i>=0; i--){
            int d = Math.abs(x - points[i][0]) + Math.abs(y - points[i][1]);
            if(d <= dis && (x == points[i][0] || y == points[i][1])){
                index = i;
                dis = d;
            }
        }
        return index;
    }
}