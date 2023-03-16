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
    TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        TreeNode* l = fun(root->left, q, p);
        TreeNode* r = fun(root->right, p, q);

        if(l == NULL) return r; //if left is NULL, return right whatever it is 
        else if(r == NULL) return l; //if right is NULL, return left whatever it is
        else return root; //if both are not NULL return root
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root, p, q);
    }
};
