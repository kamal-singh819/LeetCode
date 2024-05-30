class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        else if(x >= 0 && x <= 9) return true;
        int original = x;
        int temp = 0;
        while(x != 0){
            temp = temp*10 + x%10;
            x = x/10;
        }
        return temp == original;
    }
}