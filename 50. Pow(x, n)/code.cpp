class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long int l=abs(n);
        while(l>0){
            
            if(l%2==0){
                l=l/2;
                x=x*x;
            }
            else if(l%2!=0){
                ans=ans*x;
                l=l/2;
                x=x*x;
            }
            else if(l==0)
                break;
        }
        if(n>0)
            return ans;
        else
            return 1.0/ans;
        
    }
};
