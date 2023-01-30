class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        else if(n == 1 || n == 2)
            return 1;

        long long int a = 0, b = 1, c = 1;
        long long int z;
        for(int i=3; i<=n; i++){
            z = a+b+c;
            int temp1 = c;
            c = z;
            int temp2 = b;
            b = temp1;
            a = temp2;

        } 
        return z;       
        
    }
};
