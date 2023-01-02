	
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {   
       vector<vector<string>>ans;    
       unordered_map<string, vector<string>>mp;  //key of this map will be a string which we will get after sorting the string of given vector.

        for(int i = 0 ; i < strs.size() ; i++)
        {
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());  //sort the string
            mp[strs[i]].push_back(s);
        }
        
        //now simply put the elements  of second column of map in ans vector
        
        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;   
    }
};
