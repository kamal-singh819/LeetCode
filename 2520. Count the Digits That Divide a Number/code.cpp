class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int ans = 0;
        while(num > 0){
            int rem = num%10;
            if(rem != 0 && temp%rem == 0) ans++;

            num /= 10;
        }
        return ans;
    }
};
