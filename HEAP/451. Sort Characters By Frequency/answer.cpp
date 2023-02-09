class Solution {
public:
    string frequencySort(string s) {
        if(s.length() <= 2)
            return s;
        unordered_map<char, int> mp;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }

        //we can solve it using max heap
        priority_queue<pair<int, char>> maxHeap;
        for(auto x : mp){
            maxHeap.push({x.second, x.first});
        }

        while(!maxHeap.empty()){
            int freq = maxHeap.top().first;
            while(freq--)
                ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;

        
    }
};
