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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;

        queue<TreeNode*> q;
        q.push(root);
        while(q.front() != NULL){
            TreeNode* front = q.front();
            q.pop();
            //push left node and right node of front into the queue even NULL

            q.push(front->left);
            q.push(front->right);
        }
        while(!q.empty() && q.front() == NULL)
            q.pop();
        
        return q.empty() == true ? true : false;
    }
};
