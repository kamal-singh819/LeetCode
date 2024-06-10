class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int[] duplicate = new int[n];
        for(int i=0; i<n; i++) duplicate[i] = heights[i];
        
        Arrays.sort(heights);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(duplicate[i] != heights[i]) ans++;
        }
        return ans;
    }
}