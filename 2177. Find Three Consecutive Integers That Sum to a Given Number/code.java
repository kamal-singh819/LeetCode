class Solution {
    public long[] sumOfThree(long num) {
        long [] arr = new long[3];
        if(num % 3 != 0){
            long [] arr1 = {};
            return arr1;
        }
        long x = num/3;
        arr[0] = x-1;
        arr[1] = x;
        arr[2] = x+1;

        return arr;
        
    }
}
