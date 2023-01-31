class Solution {
public:
    int ans = 0;
    void preOrder(TreeNode* root,int flag){
        if((root->left == NULL && root->right == NULL))
        {
            if(flag==1)
                ans=ans+root->val;
            return;
        }
        if(root->left)
            preOrder(root->left,1);
        if(root->right)
            preOrder(root->right,0);
          
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left)
            preOrder(root->left,1);
        if(root->right)
            preOrder(root->right,0);
        return ans;     
    }
};
