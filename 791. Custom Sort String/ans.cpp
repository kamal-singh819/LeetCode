class Solution {
public:
    string customSortString(string order, string s) {
        if(order.length() == 1 && s.length() == 1){
            return s;    
        }
        int sizOfs = s.length();
        string ans = "";

        unordered_map<char, int> smap; //map for string s, we will store count for each character
        for(int i=0; i<sizOfs; i++){
            smap[s[i]]++;
        }

        for(int i=0; i<order.length(); i++){
            char ch = order[i];
            int count = smap[ch]; //how many times character 'ch' has come in string s---
            for(int j=0; j<count; j++){
                ans.push_back(ch);
            }
        }

        for(int i=0; i<sizOfs; i++){  //to add non-common characters (non-common between 'order' and 's')
            if(count(order.begin(), order.end(), s[i]) == 0)
                ans.push_back(s[i]);
        }

        return ans;

        
    }
};
