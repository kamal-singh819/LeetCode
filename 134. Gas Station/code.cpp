class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int lowestIndex = 0;
        int totalGas = 0;
        int totalCost = 0;
        int siz = gas.size();
        int currGas = 0;
        for(int i=0; i<siz; i++){
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += gas[i] - cost[i];

            if(currGas < 0){
                currGas = 0;
                lowestIndex = i+1;
            }
        }

        if(totalGas >= totalCost)
            return lowestIndex;
        return -1;   
    }
};
