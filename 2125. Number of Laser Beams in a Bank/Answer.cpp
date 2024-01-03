class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();  //no. of rows
        int n = bank[0].size();  //no. of column
        vector<int> deviecs(m, 0); // because there is m no. of rows
        for(int i=0;i<m;i++){
            int cntDevices = count(bank[i].begin(),bank[i].end(),'1');
            deviecs[i] = cntDevices;
        }
        
        int ans = 0;
        int prev = deviecs[0];
        for(int i=1; i<m; i++){
            if(deviecs[i] == 0)
                continue;
            else{
                ans += prev*deviecs[i];
                prev = deviecs[i];
            }  
        }
        return ans;
    }
};

