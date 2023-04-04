class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int sum = n*(n+1)/2;
        int i = 1;
        int j = n;
        int mid = (i+j)/2;
        while(i <= j){
            if(mid*(mid+1)/2 == sum-(mid*(mid-1)/2)) return mid;
            else if(mid*(mid+1)/2 < sum-(mid*(mid-1)/2)) i = mid+1;
            else j = mid-1;
            mid = (i+j)/2;
        }
        return -1;
    }
};
