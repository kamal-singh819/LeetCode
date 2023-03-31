class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2) return (long long)(skill[0]*skill[1]);
        if(n%2 != 0) return -1;
        int teams = n/2;
        long long total = 0;
        for(int i=0; i<n; i++) total += (long long)skill[i];
        long long perTeam = total/(long long)teams;
        //cout<<"per team : "<<perTeam<<endl;
        if(total%teams != 0) return -1;

        long long ans = 0;
        sort(skill.begin(), skill.end());
        for(int i=0; i<n/2; i++){
            if(skill[i]+skill[n-1-i] == perTeam) ans += (long long)(skill[i]*skill[n-1-i]);
            else return -1;
        }
        return ans;
    }
};
