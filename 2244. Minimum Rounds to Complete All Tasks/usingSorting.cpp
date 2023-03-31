class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        if(n <= 1) return -1;
        int ans = 0;
        sort(tasks.begin(), tasks.end());
        int i=0, j=0;
        while(i < n){
            j = i+1;
            while(j < n && tasks[j] == tasks[i]) j++;
            int p = j-i;
            if(p <= 1) return -1;
            if(p%3 == 0) ans += p/3;
            else ans += (p/3 + 1);
            i = j;
        }
        return ans;
    }
};
