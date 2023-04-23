class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        int maxPenCanBuy = (total/cost1) + 1; //0 is also possible
        for(int i=0; i < maxPenCanBuy; i++){
            int remainingCost = total - i*cost1;
            int maxPencilCanBuy = (remainingCost/cost2)+1;
            ans += maxPencilCanBuy;
        }
        return ans;
    }
};
