class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        if(n <= 1) return -1;
        int ans = 0;
        unordered_map<int, int> mp; //stores count 
        for(int x : tasks) mp[x]++;

        for(int x : tasks){
            if(mp.size()==0) break;
            if(mp.count(x) && mp[x] >= 2){
                if(mp[x] == 4) mp[x] -= 2;
                else if(mp[x] >= 3) mp[x] -= 3;
                else if(mp[x] == 2) mp[x] -= 2;
                ans++;
                if(mp[x] == 0) mp.erase(x);
            }
        }
        return mp.size() ? -1 : ans;  
    }
};
