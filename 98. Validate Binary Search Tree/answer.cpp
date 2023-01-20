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

//I HAVE SOLVED USING STACK----------------------- BUT WE CAN SOLVE IT USING INORDER TRAVERSAL, BECAUSE INORDER TRAVERSAL OF BST IS ALWAYS SORTED. AFTER CALCULATE 
// INORDER OF GIVEN TREE, THEN CHECK IS ARRAY IS SORTED???????????????????
class Solution {
public:
    bool ans = true;

    void recursionInorder(TreeNode* root, stack<long long int> &st){
        if(root == NULL)
            return;

        recursionInorder(root->left, st);
        if(root->val > st.top())
            st.push(root->val);
        else{
            ans = false;
            return;
        } 
        recursionInorder(root->right, st);       
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;

        if(root->left == NULL && root->right == NULL)
            return true;
        stack<long long int> st;
        long long int t = -214748364823; 
        st.push(t);
        recursionInorder(root, st);

        return ans;    
    }
};
