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
    void recursion(TreeNode* root, int targetSum, int sum, bool &ans){
        if(root == NULL)
            return;
        
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans = true;
                return;
            }
        } 
        if(root->left)
            recursion(root->left, targetSum, sum, ans);
        if(root->right)
            recursion(root->right, targetSum, sum, ans);       
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int sum = 0;
        recursion(root, targetSum, sum, ans);

        return ans;
        
    }
};
