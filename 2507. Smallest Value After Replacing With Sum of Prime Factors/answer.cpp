class Solution {
public:
    int smallestValue(int n) {
        int original = n;
        int m = 100000/2;
        vector<int> prime; //store some prime numbers under 1000 (constrains)
        vector<bool> visprime(m+1, true);
        visprime[0] = false;
        visprime[1] = false;
        for(int i=2; i<=m; i++){
            if(visprime[i]){
                prime.push_back(i);
                for(int j=2*i; j<=m; j+=i) visprime[j] = false;
            }
        }
        int psize = prime.size();
        unordered_set<int> primeSet(prime.begin(), prime.end());
        while(n > 0){
            int temp = 0;
            int prevn = n;
            for(int i=0; i < psize && prime[i] <= n; i++){
                while(n%prime[i] == 0){
                    temp += prime[i];
                    n = n/prime[i]; 
                }
                if(temp == prevn) return temp;
                if(n == 1) break;
            }
            if(primeSet.count(temp)) return temp;
            n = temp;
        }
        return original;  
    }
};
