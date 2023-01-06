//Method-1 : Using Priority Queue    
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int siz = costs.size();
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq; //min-heap priority queue
        for(int i=0; i<siz; i++){
            pq.push(costs[i]);
        }
        
        int i=0;
        while(i < siz && coins > 0 && !pq.empty()){
            int tp = pq.top();
            pq.pop();
            if(coins >= tp){
                coins = coins-tp;
                ans++;
                i++;
            }
            else
                break;
        }
        return ans;
    }
};


//Method-2 Using simple SORT()---------------------

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int siz = costs.size();
        int ans = siz;
        sort(costs.begin(), costs.end());
        long long int total = 0;
        for(int i=0; i<siz; i++){
            total += costs[i];
        }
        int i = siz-1;
        while(total > coins && i >= 0){
            total = total - costs[i];
            i--;
            ans--;
        }
        return ans;
    }
};
