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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        //recursive calls------------
        invertTree(root->left); ///left call
        invertTree(root->right); ///right call
//wapas aate hue node swap kar denge(like post order traversal)
        TreeNode* x = root->left;
        root->left = root->right;
        root->right = x;
        return root;
        
    }
};
