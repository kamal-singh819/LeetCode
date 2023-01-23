class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        if(n == 2147483647){ //if n = INT_MAX, reduced it by two steps manually  because there can be occur integer overflow----
            n = 1073741824;
            ans = 2;
        }

        while(n != 1){
            if(n %2 == 0)
                n = n/2;
            else if(n == 3 || (n%2 == 1 && (n-1)%4 == 0))  //ex: n = 17
                n = n-1;
            else if(n%2 == 1) //ex: n = 15
                n = n+1;

            ans++;        
        }
        return ans;
        
    }
};
