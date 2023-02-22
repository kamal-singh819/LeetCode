class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        stack<int> st;
        vector<string> ans;
        vector<int> temp;
        int j = 0; //keeping track of index of target & temp
        for(int i=1; i<=n; i++){
            if(temp.size() < m){
                temp.push_back(i);
                ans.push_back("Push");
                if(temp[j] == target[j])
                    j++;
                else if(temp[j] != target[j]){
                    temp.pop_back();
                    ans.push_back("Pop");
                }
                if(temp == target)
                    return ans;
            }
            else{
                temp.pop_back();
                ans.push_back("Pop");
                i--;
            }
        }
        return ans;
        
    }
};
