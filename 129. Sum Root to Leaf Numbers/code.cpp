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
void recursionFunction(TreeNode* root, int routeSum, int &totalSum){
    if(root == NULL)
        return;

    routeSum = routeSum*10 + root->val;

    if(root->left == NULL && root->right == NULL){
        totalSum += routeSum;
        return;
    }

    if(root->left)
        recursionFunction(root->left, routeSum, totalSum);   
    if(root->right)
        recursionFunction(root->right, routeSum, totalSum);     
}
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        int routeSum = 0;

        recursionFunction(root, routeSum, totalSum);
        return totalSum;   
    }
};
