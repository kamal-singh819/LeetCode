class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        if(n <= 1)
            return n;

        Arrays.sort(nums);

        int i = 0;
        int j = 1;
        int cnt = 1;
        int ans = -1;

        while(i<n && j<n){
            if(nums[j] == nums[i]){
                i++;
                j++;
                continue;
            }
            if(nums[j]-nums[i] == 1){
                cnt++;
            }
            else{
                ans = Math.max(cnt, ans);
                cnt = 1;
            }
            i++;
            j++;
        }

        return Math.max(cnt, ans);   
    }
}
