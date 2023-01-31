class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root ==  NULL || (root->left == NULL && root->right == NULL))
            return true;
        queue<TreeNode*> q;
        bool flag = false;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                TreeNode* f = q.front();
                q.pop();
                if(flag && f->left){
                    return false;
                }
                if(f->left)
                    q.push(f->left);
                else
                    flag = true;  
                    
                      
                if(flag && f->right)
                    return false;

                if(f->right)
                    q.push(f->right);
                else
                    flag = true;          
            }

        }
        return true;
        
    }
};
