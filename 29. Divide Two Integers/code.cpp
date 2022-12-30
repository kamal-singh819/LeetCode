//Use //log & exponential

class Solution {
public:
    long long int divide(long long int dividend, long long int divisor) {
        if(dividend == 0)
             return 0;
        
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long long int sign  = (dividend < 0)^(divisor < 0);
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        if(divisor == 1){
            return (sign == 0 ? dividend : -dividend);
        }
        
        long long int ans = exp(log(dividend) - log(divisor)) + 0.0000000001;
        
        return (sign == 0 ? ans : -ans);
        
    }
};

