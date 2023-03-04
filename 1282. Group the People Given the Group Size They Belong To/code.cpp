class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto x : mp){
            int k = x.first;
            vector<int> temp;
            for(int i=0; i<x.second.size(); i++){
                temp.push_back(x.second[i]);
                if(i%k == k-1){
                    ans.push_back(temp);
                    temp.clear();
                }                
            }
        }
        return ans;
    }
};
