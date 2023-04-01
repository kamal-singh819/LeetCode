class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1,-1};
        //seive of erathentes----
        vector<bool> prime(right+1, true);
        prime[0] = false;
        prime[1] = false;
        for(int i=2; i<= right; i++){
            if(prime[i]){
                for(int j = 2*i; j<= right; j += i) prime[j] = false;
            }
        }
        int num1, num2;
        //find first prime number and store in num1
        for(int i=left; i<= right; i++){
            if(prime[i]){
                num1 = i;
                break;
            }
        }
        int diff = INT_MAX;
        for(int i=num1+1; i<= right; i++){
            if(prime[i]){
                num2 = i;
                if(num2-num1 < diff){ //compare difference
                    ans[0] = num1;
                    ans[1] = num2;
                    diff = num2-num1;
                }
                num1 = num2;
            }
        }
        return ans;  
    }
};
