class Solution {
    private void findSubsetXOR(int i, int n, int []nums, int curr, int[] ans) {
        if(i >= n){
            ans[0] += curr;
            return;
        }
        findSubsetXOR(i + 1, n, nums, curr, ans);
        curr ^= nums[i];
        findSubsetXOR(i+1, n, nums, curr, ans);
        curr ^= nums[i];
    }
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int[] ans = {0};
        findSubsetXOR(0, n, nums, 0, ans);
        return ans[0];
    }
}