/////////////////        Using Sorting        /////////////////
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long m = mass;
        if(n == 1){
            if(m >= asteroids[0]) return true;
            else return false;
        }
        sort(asteroids.begin(), asteroids.end());
        for(int i=0; i<n; i++){
            if(m >= asteroids[i]) m += asteroids[i];
            else return false;
        }
        return true; 
    }
};
