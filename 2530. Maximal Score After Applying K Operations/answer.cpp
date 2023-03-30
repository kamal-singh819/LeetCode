class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        int n = nums.size();
        priority_queue<int> pq; //max heap
        for(int i=0; i<n; i++) pq.push(nums[i]);
        while(k--){
            int mx = pq.top();
            pq.pop();
            score += (long long)mx;
            if(mx%3 == 0) pq.push(mx/3);
            else pq.push(mx/3 + 1);
        }
        return score;  
    }
};
