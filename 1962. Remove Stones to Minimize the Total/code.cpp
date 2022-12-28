//We can use priority queue to solve this problem.

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int ans = 0;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(piles[i]);
        }

        for(int i=0; i<k; i++){
            int x = pq.top();
            pq.pop();
            x = x-(x/2);
            pq.push(x);
        }

        for(int i=0; i<n; i++){
            int x = pq.top();
            pq.pop();
            ans += x;
        }
        return ans;
        
    }
};
