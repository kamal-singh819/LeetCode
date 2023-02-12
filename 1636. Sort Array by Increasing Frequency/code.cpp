class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first) //if first value of pair are equal, sort in decending order by its second value
            return a.second > b.second;
        return a.first < b.first; //else sort in ascending order
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> ump; //will store the elements with their frequency 
        for(int x : nums)
            ump[x]++;

        vector<pair<int, int> > vp;

        for(auto x : ump){
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end(), comp);

        for(auto x : vp){
            int val = x.second;
            int freq = x.first;
            for(int i=0; i<freq; i++)
                ans.push_back(val);
        }

        return ans;
        
        
    }
};
