class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        //if some zeros are at starting increase i and j until -1 or 1 occur
        while(i < n && forts[i] == 0) i++;
        j = i;
        while(i < n && j < n){
            if(i < n-1 && forts[i] == 1 && forts[i+1] == 1) i++;
            else if(i < n-1 && forts[i] == -1 && forts[i+1] == -1) i++;
            j = i;
            if(j < n && forts[j] == 1){
                while(i < n-1 && forts[i+1] == 0) i++;
                if(i < n-1 && forts[i+1] == -1) ans = max(ans, i-j);
                j = i+1;  
            }
            else if(j < n && forts[j] == -1){
                while(i < n-1 && forts[i+1] == 0) i++;
                if(i < n-1 && forts[i+1] == 1) ans = max(ans, i-j);
                j = i+1;
            }
            i++;
        }
        return ans;  
    }
};
