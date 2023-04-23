class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int M = 1e9+7;
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); //min heap
        long long ans = 1;

        while(k--){
            int tp = pq.top();
            pq.pop();
            pq.push(tp+1);
        }
        while(!pq.empty()){
            ans *= pq.top();
            pq.pop();
            ans = ans%M;
        }
        return (int)ans;
    }
};
