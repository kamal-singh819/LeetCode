class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = ceil(sqrt(c)) + 1;
        
        unordered_set<long long> uset;
        for(long long i=0; i<=limit; i++){
            uset.insert(i*i);
        }
        for(auto x : uset){
            if(c >= x){
                long long z = (c-x);
                if(uset.count(z))
                    return true;
            }
        }
        return false;
        
    }
};
