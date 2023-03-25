class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> uset;
        for(int x : banned) uset.insert(x);

        int sum = 0;
        int count = 0;
        for(int i=1; i<=n; i++){
            if(!uset.count(i) && sum < maxSum){
                count++;
                sum += i;
                if(sum > maxSum) return count-1;
            }
        }
        return count;
    }
};



class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        sort(banned.begin(), banned.end());
        int j = 0; //iterate through banned array
        int i = 1;
        int ans = 0;
        int sum = 0;
        while(i <= n){
            if(j < m && i == banned[j]){
                while(j < m && i == banned[j]) j++;
            }
            else{
                sum += i;
                if(sum <= maxSum) ans++;
                else break;
            }
            i++;
        }
        return ans;  
    }
};
