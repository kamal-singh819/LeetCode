class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        int m = v2.size();
        if(n > m) return findMedianSortedArrays(v2, v1);
        int low = 0;
        int high = n;
        while(low <= high){
            int i1 = (low+high)/2;
            int i2 = (n+m+1)/2 - i1;
            
            int max1 = (i1 == 0) ? INT_MIN : v1[i1-1];
            int max2 = (i2 == 0) ? INT_MIN : v2[i2-1];
            
            int min1 = (i1 == n) ? INT_MAX : v1[i1];
            int min2 = (i2 == m) ? INT_MAX : v2[i2];
            
            if(max1 <= min2 && max2 <= min1){
                if((n+m)%2 == 0) return (max(max1, max2) + min(min1, min2))/2.0;
                else return max(max1, max2);
            }
            else if(max1 > min2) high = i1-1;
            else low = i1+1;
        }
        return 0.0;
    }
};
