class Solution {
private:
    long long summation(long long i, long long j, int &kk, int &k){
        if(i == j || i+1 == j) return 0;
        if(k-kk >= j-i-1){
            kk += j-i-1;
            return (j*(j-1))/2 - (i*(i+1))/2;
        }
        else{
            j = i + (k-kk+1);
            kk = k;
            return (j*(j-1))/2 - (i*(i+1))/2;
        }
        return 0;
    }
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        
        int kk = 0;
        int i = 0;
        if(n == 1){
            ans += summation(0, (long long)nums[0], kk, k);
        }
        else{
            while(i < n-1){
                if(i == 0){
                    ans += summation((long long)0, (long long)nums[0], kk, k);
                }
                ans += summation((long long)nums[i], (long long)nums[i+1], kk, k);
                if(kk == k) return ans;
                i++;
            }
        }

        if(kk == k) return ans;
        long long last = nums[n-1];
        if(kk < k){
            ans += summation(last, (long long)(last+k-kk+1), kk, k);
        }
        return ans;  
    }
};
