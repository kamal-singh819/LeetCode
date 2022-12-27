class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        if(n == 1){
            if(capacity[0]-rocks[0] <= additionalRocks)
                return 1;
            else
                return 0;    
        }
        vector<int> need; //a vector which keeps track which bags need how many rocks more?
        int ans = 0;
        for(int i=0; i<n; i++){
            need.push_back(capacity[i]-rocks[i]);
        }
        sort(need.begin(), need.end());

        for(int i=0; i<n; i++){
            if(need[i] != 0 && additionalRocks > 0){
                int x = need[i];
                additionalRocks -= x;
                if(additionalRocks >= 0)
                    need[i] = 0;
                else
                    break;    
            }
        }

        for(int i=0; i<n; i++){
            if(need[i] == 0)
                ans++;
            else
                break;
        }
        return ans;        
    }
};
