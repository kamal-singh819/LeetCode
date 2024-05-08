class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> temp = score;
        vector<string> ans;
        sort(temp.begin(), temp.end());
        for(int i=0; i<n; i++) {
            int index = lower_bound(temp.begin(), temp.end(), score[i]) - temp.begin();
            int pos = n - index;
            if(pos == 1) ans.push_back("Gold Medal");
            else if(pos == 2) ans.push_back("Silver Medal");
            else if(pos == 3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(pos));
        }
        return ans;
    }
};