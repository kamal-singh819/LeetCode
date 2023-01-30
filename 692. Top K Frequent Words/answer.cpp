class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mp;
        vector<pair<int, string>> vp; //vector of pairs of int and string----
        for(auto i : words){
            mp[i]++;
        }

        for(auto x : mp){
            vp.push_back({x.second, x.first});

        }
        
      //a comparator 
        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        
        sort(vp.begin(), vp.end(), lambda); //lambda is comparator 

        int i=0;
        while(i < k){
            ans.push_back(vp[i].second);
            i++;
        }
        return ans;        
    }
};
