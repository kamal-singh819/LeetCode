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
    int count = 0;
    void preorderTraversal(TreeNode* root){
        if(root == NULL)
            return;
        count++;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;

        preorderTraversal(root);    

        // int count = 0;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     root = st.top();
        //     st.pop();
        //     count++;
        //     if(root->right)
        //         st.push(root->right);
        //     if(root->left)
        //         st.push(root->left);    
        // }  
        return count;      
        
    }
};
