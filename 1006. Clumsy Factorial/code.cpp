class Solution {
public:
    int clumsy(int n) {
        if(n <= 2)
            return n;
        int N = n;
        long long ans = 2*(N*(N-1)/(N-2));
        for(int i=1; i<=n && N>0; i++){
            if(i%2 == 1){
                long long m = 0;
                if(N == 1){
                    m = 1;
                    N = N-1;
                }
                else if(N == 2){
                    m = 2*1;
                    N = N-2;
                }
                else{
                    m = N*(N-1)/(N-2);
                    N = N-3;
                }
                ans -= m;
            }
            else{
                ans += N;
                N = N-1;
            }
        }
        return ans;
        
    }
};












///////////////////////////////////////////OR/////////////////////////////////////////////

class Solution {
public:
    int clumsy(int n) {
        if(n <= 2)
            return n;
        int N = n;
        long long ans = 2*(N*(N-1)/(N-2));

        for(int i=1; i<=n && N>0; i++){ 
            long long m = 0;
            if(N == 1){
                m = 1;
                N = N-1;
            }
            else if(N == 2){
                m = 2*1;
                N = N-2;
            }
            else{
                m = N*(N-1)/(N-2);
                N = N-3;
            }
            ans -= m;
            if(N == 0)
                break;
            ans += N;
            N = N-1;
        }
        return ans;
        
    }
};
