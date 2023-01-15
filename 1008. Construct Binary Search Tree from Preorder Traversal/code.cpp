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
    void insertIntoBST(TreeNode* &temp, int data){
        if(temp == NULL){
            temp = new TreeNode(data);
            return;
        }

        if(temp->val > data){
            insertIntoBST(temp->left, data);
        }
        if(temp->val < data){
            insertIntoBST(temp->right, data);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* temp = root;

        for(int i=1; i<preorder.size(); i++){
            insertIntoBST(temp, preorder[i]);
        }
        return root;
        
    }
};
