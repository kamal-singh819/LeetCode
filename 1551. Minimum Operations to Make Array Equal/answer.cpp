class Solution {
public:
    int minOperations(int n) {
        int long long ans;
        int half;
        if(n%2 == 0){  
            half = n/2 - 1;
            ans = 1; //i.e there are two middle's of the array, need one extra operation in this case
        }
        else{
            half = n/2;
            ans = 0; //i.e there is only one middle of the array, no need of extra operation in this case
        }

        for(int i=0; i<half; i++){
            int required = n - (2*i + 1);
            ans += required;
        }
        return ans;
        
    }
};
