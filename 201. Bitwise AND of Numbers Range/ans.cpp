class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 || right == 0)
            return 0;
        
        if((int)log2(left) != (int)log2(right))
            return 0;
            
        long long ans = left;
        for(long long i=(long long)left+1; i<=(long long)right; i++)
            ans = ans & i;

        return ans;    
        
    }
};
