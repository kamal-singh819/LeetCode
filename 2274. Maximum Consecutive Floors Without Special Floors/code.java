class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        int n = special.length;
        if(top-bottom+1 == n)
            return 0;
        if(n == 1){
            return Math.max(special[0]-bottom, top-special[0]);
        }
        Arrays.sort(special);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i==0){
                int res = special[i] - bottom; //floor between special[0] and bottom
                ans = Math.max(ans, res);
            }
            else if(i == n-1){
                int res = top - special[i]; //floor between top and special[n-1]
                ans = Math.max(ans, res);
            }
            if(i<n-1){
                int res1 = special[i+1] - special[i] - 1;
                ans = Math.max(ans, res1);
            }
        }

        return ans;
    }
}
