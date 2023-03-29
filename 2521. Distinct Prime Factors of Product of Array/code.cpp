class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st; //stores unique prime number
        int n = nums.size();
        vector<int> prime; //store some prime numbers under 1000 (constrains)
        for(int i=2; i<=1000; i++){
            bool flag = true;
            for(int j=2; j<i; j++){
                if(i%j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag) prime.push_back(i);
        }
        // cout<<prime.size(); 168 prime numbers under 1000
        //------------------------------------------------------------
        for(int num : nums){
            for(int i=0; i < prime.size() && prime[i] <= num; i++){
                while(num%prime[i] == 0){
                    st.insert(prime[i]);
                    num = num/prime[i];
                }
                if(num == 1) break;
            }
        }
        return st.size();
    }
};
