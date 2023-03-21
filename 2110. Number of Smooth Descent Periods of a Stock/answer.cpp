class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 1;
        long long ans = 0;
        ans += n; //all single element is a smooth descent
        int i =0;
        while(i < n-1){
            long long count = 1;
            bool flag = false;
            while(i < n-1 && prices[i] - prices[i+1] == 1){
                count++;
                i++;
                flag = true;
            }
            if(count > 1) ans += ((count*(count+1)/2) - count);
            //we have subtract 'count' from the count of all subarrays because we have already add
            // answer into 'ans' for size 1...
            if(flag == false) i++;
        }
        return ans;
        
    }
};
