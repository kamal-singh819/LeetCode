class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int siz = chalk.size();
        if(siz <= 1)
            return 0;

        int long long summ = 0; //total sum of pieces of chalks...
        for(int i=0; i<siz; i++){
            summ += chalk[i];
        }  

        k = k%summ; /////////////////////////

        for(int i=0; i<siz; i++){
            if(k >= chalk[i])
                k -= chalk[i];

            else
                return i;    
        }  
        return 0;
        
    }
};
