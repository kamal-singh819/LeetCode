class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> ans;
        int i = n-1;
        int temp = 0;
        while(i >= 0 || k != 0 || temp == 1){
            if(i >= 0)
                temp = temp + num[i];
            if(k != 0){
                temp = temp + k%10;
                k = k/10;
            }
            ans.push_back(temp%10);
            temp = temp/10;
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
