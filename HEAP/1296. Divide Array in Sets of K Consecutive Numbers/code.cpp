class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0)
            return false;
        
        priority_queue<int, vector<int>, greater<int> > minh;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            minh.push(nums[i]);
            mp[nums[i]]++;
        }

        while(!minh.empty()){
            int tp = minh.top();
            if(mp.find(tp) == mp.end() || mp[tp] == 0){
                minh.pop();
                continue;
            }
            mp[tp]--;
            for(int i=1; i<k; i++){
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
