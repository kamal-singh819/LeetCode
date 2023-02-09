class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;

        unordered_map<char, unordered_set<string> > mp;
        for(auto x : ideas){
            mp[x[0]].insert(x.substr(1));
        }

        for(auto char1 : mp){
            for(auto char2 : mp){
                if(char1.first == char2.first)
                    continue;
                
                int inner = 0;
                for(auto word : char1.second){
                    if(char2.second.find(word) != char2.second.end())
                        inner++;

                }

                int distinct1 = char1.second.size() - inner;
                int distinct2 = char2.second.size() - inner;

                ans += (distinct1 * distinct2);
            }
        }

        return ans;
        
    }
};
