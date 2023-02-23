class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() %groupSize != 0)
            return false;
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int> > minh;
        for(int i=0; i<hand.size(); i++){
            mp[hand[i]]++;
            minh.push(hand[i]);
        }
        
        while(!minh.empty()){
            int tp = minh.top();
            if(mp.find(tp) == mp.end() || mp[tp] == 0){
                minh.pop();
                continue;
            }
            mp[tp]--;
            for(int i=1; i<groupSize; i++){
                if(mp.find(tp+i) == mp.end() || mp[tp+i] == 0)
                    return false;
                mp[tp+i]--;
            }
            if(mp[tp] == 0){
                minh.pop();
                mp.erase(tp);
            }
        }
        return true;    
    }
};
