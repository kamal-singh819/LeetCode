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
    bool function(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL) return true;
        if((l == NULL && r != NULL) || (l != NULL && r == NULL)) return false;
        if(l->val != r->val) return false;

        bool first = function(l->left, r->right);
        bool second = function(l->right, r->left);
        return first && second;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;

        return function(root->left, root->right);   
    }
};
