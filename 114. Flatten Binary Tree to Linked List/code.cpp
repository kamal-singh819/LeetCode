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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            return;
        
        TreeNode* temp = root;
        root = NULL;
        TreeNode* p = root;
        st.push(temp);
        while(!st.empty()){
            TreeNode* tp = st.top();
            st.pop();
            if(root == NULL){
                root = tp;
                p = tp;
            }
            else{
                p->right = tp;
                p->left = NULL;
                p = p->right;
            }
            if(tp->right)
                st.push(tp->right);
            if(tp->left)
                st.push(tp->left);

        }  
    }
};
