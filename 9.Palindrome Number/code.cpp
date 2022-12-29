class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long rev=0;
        if(x<0)
            return false;
        else if(x==0)
            return true;
        else
        {
            while(x!=0)
            {
                 int rem = x % 10;
                 rev = rev * 10 + rem;
                 x =x/10;
                
            }
            if(rev==num)
                return true;
            else 
                return false;
        }
        return false;
    }
};
