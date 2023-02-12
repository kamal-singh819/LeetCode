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
     bool areSymmetric(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == NULL && rightRoot == NULL)
            return true;
        
        if((leftRoot == NULL && rightRoot != NULL) || (leftRoot != NULL && rightRoot == NULL))
            return false;
        
        if(leftRoot->val != rightRoot->val)
            return false;

        return (areSymmetric(leftRoot->left, rightRoot->right) && areSymmetric(leftRoot->right, rightRoot->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        
        return areSymmetric(root->left, root->right);
        
    }
};
