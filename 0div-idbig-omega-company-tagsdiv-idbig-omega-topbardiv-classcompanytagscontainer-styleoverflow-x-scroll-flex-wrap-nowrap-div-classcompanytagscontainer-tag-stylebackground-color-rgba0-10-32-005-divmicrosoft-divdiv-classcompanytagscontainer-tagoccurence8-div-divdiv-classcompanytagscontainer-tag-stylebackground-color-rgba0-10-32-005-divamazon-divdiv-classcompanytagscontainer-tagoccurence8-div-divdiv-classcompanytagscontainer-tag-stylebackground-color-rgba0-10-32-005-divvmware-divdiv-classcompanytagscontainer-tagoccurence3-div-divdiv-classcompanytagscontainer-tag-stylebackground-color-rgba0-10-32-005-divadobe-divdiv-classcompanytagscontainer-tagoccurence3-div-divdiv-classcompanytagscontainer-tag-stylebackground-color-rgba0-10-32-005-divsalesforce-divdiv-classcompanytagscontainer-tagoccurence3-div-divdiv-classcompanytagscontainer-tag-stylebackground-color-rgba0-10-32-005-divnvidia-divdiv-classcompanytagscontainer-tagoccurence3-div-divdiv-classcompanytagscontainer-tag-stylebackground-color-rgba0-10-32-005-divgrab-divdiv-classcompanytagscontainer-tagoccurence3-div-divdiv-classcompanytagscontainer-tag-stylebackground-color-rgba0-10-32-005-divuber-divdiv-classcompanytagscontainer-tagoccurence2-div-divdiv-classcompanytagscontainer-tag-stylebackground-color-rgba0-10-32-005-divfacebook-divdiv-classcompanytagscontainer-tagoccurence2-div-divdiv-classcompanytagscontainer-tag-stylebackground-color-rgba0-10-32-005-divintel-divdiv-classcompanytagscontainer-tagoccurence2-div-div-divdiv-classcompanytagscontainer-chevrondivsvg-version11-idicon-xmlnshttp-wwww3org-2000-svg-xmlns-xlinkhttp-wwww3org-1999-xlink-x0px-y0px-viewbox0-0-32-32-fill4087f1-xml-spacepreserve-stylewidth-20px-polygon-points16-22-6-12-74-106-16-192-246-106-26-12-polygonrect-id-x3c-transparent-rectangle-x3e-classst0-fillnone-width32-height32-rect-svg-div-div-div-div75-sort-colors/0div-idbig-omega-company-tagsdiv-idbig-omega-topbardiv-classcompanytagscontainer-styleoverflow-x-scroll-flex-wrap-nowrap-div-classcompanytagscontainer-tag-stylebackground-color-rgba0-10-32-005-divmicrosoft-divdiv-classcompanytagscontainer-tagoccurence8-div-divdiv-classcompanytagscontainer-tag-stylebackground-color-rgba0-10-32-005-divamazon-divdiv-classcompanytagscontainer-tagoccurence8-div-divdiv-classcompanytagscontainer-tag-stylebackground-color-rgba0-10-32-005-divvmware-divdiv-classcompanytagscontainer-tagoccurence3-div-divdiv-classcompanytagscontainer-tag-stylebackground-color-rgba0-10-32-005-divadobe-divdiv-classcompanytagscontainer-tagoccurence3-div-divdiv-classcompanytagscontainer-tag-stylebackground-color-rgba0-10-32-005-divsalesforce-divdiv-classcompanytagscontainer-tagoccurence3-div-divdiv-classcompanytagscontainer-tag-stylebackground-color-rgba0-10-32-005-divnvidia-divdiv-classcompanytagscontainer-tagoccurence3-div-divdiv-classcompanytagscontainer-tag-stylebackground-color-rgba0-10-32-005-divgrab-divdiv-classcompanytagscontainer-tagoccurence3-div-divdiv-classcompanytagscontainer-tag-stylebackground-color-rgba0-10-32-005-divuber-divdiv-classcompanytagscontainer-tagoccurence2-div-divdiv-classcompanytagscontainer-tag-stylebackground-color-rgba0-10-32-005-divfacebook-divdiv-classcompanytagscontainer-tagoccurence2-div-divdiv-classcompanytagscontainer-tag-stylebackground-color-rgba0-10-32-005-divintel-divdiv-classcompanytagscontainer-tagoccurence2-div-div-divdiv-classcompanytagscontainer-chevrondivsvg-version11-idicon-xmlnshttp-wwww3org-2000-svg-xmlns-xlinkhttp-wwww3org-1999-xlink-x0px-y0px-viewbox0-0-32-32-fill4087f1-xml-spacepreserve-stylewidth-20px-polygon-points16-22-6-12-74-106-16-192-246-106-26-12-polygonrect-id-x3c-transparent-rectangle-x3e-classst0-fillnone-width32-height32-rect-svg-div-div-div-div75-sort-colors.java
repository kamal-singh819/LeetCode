class Solution {
    void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    public void sortColors(int[] nums) {
        int i = 0;
        int j = nums.length-1;
        int mid = 0;
        while(mid <= j){
            if(nums[mid] == 0){
                swap(nums, i, mid);
                i++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums, mid, j);
                j--;
            }
        }
    }
}