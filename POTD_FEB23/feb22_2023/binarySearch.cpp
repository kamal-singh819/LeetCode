class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int total = 0;
        for(int i=0; i<n; i++)
            total += weights[i];
        
        if(days == 1)
            return total;
        
        int maxx = *max_element(weights.begin(), weights.end()); //maxx is start and total is end of search space

        int s = maxx; //representing to start of search space
        int e = total; //representing to end of search space
        while(s < e){
            int mid = s + (e-s)/2;
            int add = 0;
            int countDay = 1;
            for(int x : weights){
                if(add + x > mid){
                    add = 0;
                    countDay++;
                }
                add += x;
            }

            if(countDay <= days)
                e = mid;
            else
                s = mid+1;
        }
        return s;
        
    }
};
