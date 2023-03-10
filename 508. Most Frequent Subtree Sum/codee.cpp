/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int function(TreeNode* root, unordered_map<int, int> &mp){
        if(root == NULL) return 0;

        int currsum = root->val + function(root->left, mp) + function(root->right, mp);

        mp[currsum]++;
        return currsum;
    }
    static bool comp(pair<int, int> a, pair<int, int> b){
        if(a.first > b.first) return true;
        return false;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root->left && !root->right) return {root->val};
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<pair<int, int> > v;
        function(root, mp);
        
        for(auto x : mp){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(), comp);
        for(int i=0; i<v.size(); i++){
            if(v[0].first == v[i].first){
                ans.push_back(v[i].second);
            }else break;
        }
        return ans;
    }
};
