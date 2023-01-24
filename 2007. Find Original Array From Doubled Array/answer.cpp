class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> emptyAns;
        vector<int> ans;
        if(changed.size()%2 != 0)
            return emptyAns;
        unordered_map<int, int> mp;

        for(int x : changed)
            mp[x]++;
        

        sort(changed.begin(), changed.end());
        for(int i=0; i<changed.size(); i++){
            int y = changed[i];
            if (mp[y] == 0)
                continue;

            if(mp[y*2] == 0)
                return emptyAns;  
            
            ans.push_back(y);
            mp[y]--;
            mp[y*2]--;      
        } 

        return ans;   
        
    }
};
