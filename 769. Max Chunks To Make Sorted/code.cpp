class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        int i=1;
        int ans = 0;
        int sum1, sum2;

        sum1 = 0;
        sum2 = 0;
        while(i <= n){
            if(sum1+arr[i-1] == sum2+sorted[i-1]){
                ans++;
                i++;
            }
            else{
                while(i <= n && sum1+arr[i-1] != sum2+sorted[i-1]){
                    sum1 += arr[i-1];
                    sum2 += sorted[i-1];
                    i++;
                }
                ans++;
                i++;
                if(i <= n){
                    sum1 = 0;
                    sum2 = 0;
                }
            }
        }
        return ans; 
    }
};
