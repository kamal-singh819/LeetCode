/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool fun(TreeNode* root, TreeNode* f, vector<TreeNode*> &v){
        if(root == NULL) return false;
        v.push_back(root);
        if(root == f) return true;

        bool l = fun(root->left, f, v);
        bool r = fun(root->right, f, v);
        if(l || r) return true;
        v.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;
        fun(root, p, pv);
        fun(root, q, qv);
        int i = 0;
        while(pv[i]->val == qv[i]->val){
            i++;
            if(i == pv.size() || i == qv.size())
                return pv[i-1];
        }
        return pv[i-1];   
    }
};
