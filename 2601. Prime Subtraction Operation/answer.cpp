//Time Complexity is O(N*N*sqrt(N)) and Space Complexity is O(1).
class Solution {
private:
    bool isPrime(int num){
        for(int i=2; i<=sqrt(num); i++){
            if(num%i == 0) return false;
        }
        return true;
    }
    int find(int a, int b){
        for(int i=2; i<a; i++){
            if(isPrime(i)){
                if(a-i < b) return i; //prime number found
            }
        }
        return -1; //prime number is not found
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1; i>=1; i--){
            if(nums[i-1] < nums[i]) continue;
            else{
                int primeNo = find(nums[i-1], nums[i]);
                if(primeNo == -1) return false; //not possible to make array strictly incresing
                nums[i-1] = nums[i-1] - primeNo;
            }
        }
        return true;   
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//->every time we are checking a number is prime or not, Can we do better? YES using
//   ```sieve of eratosthenes algorithm```

class Solution {
private:
    int find(int a, int b, vector<bool> &prime){
        for(int i=2; i<a; i++){
            if(prime[i]){
                if(a-i < b) return i; //prime number found
            }
        }
        return -1; //prime number is not found
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        //sieve of eratosthenes algorithm to store all prime number in a vector
        vector<bool> prime(1001, true); //mark all numbers is prime initially
        prime[0] = false;
        prime[1] = false;
        for(int i=2; i<=1000; i++){
            if(prime[i]){
                for(int j=2*i; j<=1000; j += i)
                    prime[j] = false;
            }
        }
        /////////////////////////////////////////////////////////////////
        for(int i=n-1; i>=1; i--){
            if(nums[i-1] < nums[i]) continue;
            else{
                int primeNo = find(nums[i-1], nums[i], prime);
                if(primeNo == -1) return false; //not possible to make array strictly incresing
                nums[i-1] = nums[i-1] - primeNo;
            }
        }
        return true;   
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Time Complexity is O(N*logN) as we are using Binary search in find function instead of linear search. 
//And space complexity is O(2N)
class Solution {
private:
    int find(int a, int b, vector<int> &primeNumbers){
        int ind =  upper_bound(primeNumbers.begin(), primeNumbers.end(), a-b) - primeNumbers.begin();
        if(ind >= primeNumbers.size()) return -1;
        if(primeNumbers[ind] < a) return primeNumbers[ind];
        return -1; //prime number is not found
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        //sieve of eratosthenes algorithm to store all prime number in a vector
        vector<bool> prime(1001, true); //mark all numbers is prime initially
        vector<int> primeNumbers;
        prime[0] = false;
        prime[1] = false;
        for(int i=2; i<=1000; i++){
            if(prime[i]){
                primeNumbers.push_back(i);
                for(int j=2*i; j<=1000; j += i)
                    prime[j] = false;
            }
        }
        /////////////////////////////////////////////////////////////////
        for(int i=n-1; i>=1; i--){
            if(nums[i-1] < nums[i]) continue;
            else{
                int primeNo = find(nums[i-1], nums[i], primeNumbers);
                if(primeNo == -1) return false; //not possible to make array strictly incresing
                nums[i-1] = nums[i-1] - primeNo;
            }
        }
        return true;   
    }
};
