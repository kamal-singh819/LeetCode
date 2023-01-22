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

//we will use INORDER TRAVERSAL TO SOLVE THIS 
class Solution {
public:
    int ans;
    void inOrderTraversal(TreeNode* root, int &k){
        if(root == NULL)
            return;
        
        inOrderTraversal(root->left, k);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        inOrderTraversal(root->right, k); 

    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);

        return ans;
        
    }
};
