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
void fun(TreeNode* root, string route, string &v, string alpha){
    if(root == NULL) return;
    route = (alpha[root->val]) + route;

    if(!root->left && !root->right){
        v = min(v, route);
        return;
    }
    if(root->left) fun(root->left, route, v, alpha);
    if(root->right) fun(root->right, route, v, alpha);
}
public:
    string smallestFromLeaf(TreeNode* root) {
        string v = "zzzzzzzzzzzzzzzzzzzzzzzzz";
        string route = "";
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        fun(root, route, v, alpha);
        return v;     
    }
};
