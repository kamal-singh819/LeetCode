class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp; //basket--()
        int ans = 0;
        int i=0, j=0; 
        //variable size sliding window--
        while(j<n){
            mp[fruits[j]]++;
            while(i<n && mp.size() > 2){
                if(mp[fruits[i]] == 1)
                    mp.erase(fruits[i]);
                else
                    mp[fruits[i]]--;
                
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;    
    }
};

/////////////////////////////////////////////////////////////////////My own////////////////////////////

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int i=0;
        int j=0;
        while(j < n){
            mp[fruits[j]]++;
            // if(mp.size() < 2)
            //     j++;
            if(mp.size() <= 2){
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                while(mp.size() > 2){
                    if(mp[fruits[i]] == 1)
                        mp.erase(fruits[i]);
                    else
                        mp[fruits[i]]--;
                    
                    i++;
                }
                j++;
            }
        }
        return ans;        
    }
};
