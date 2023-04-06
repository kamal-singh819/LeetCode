class Solution {
private:
    bool isPossibleToDistribue(int x, int &n, vector<int> &quant){
        long long stores = 0;
        for(int i=0; i<quant.size(); i++){
            if(quant[i]%x == 0) stores += quant[i]/x;
            else stores += (quant[i]/x + 1);
            //we can write above two line using ceil() function in a single line
        }
        return stores <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        //we can try linearly for x from 0 to max(quantities[i])
        //But it will give TLE
        //Use Binary Search
        int low = 1;
        int high = 1e5;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossibleToDistribue(mid, n, quant)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;  
    }
};
