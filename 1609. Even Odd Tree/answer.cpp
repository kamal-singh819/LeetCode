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
    bool isEvenOddTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL && root->val%2 != 0) return true;
        if(root->left == NULL && root->right == NULL && root->val%2 == 0) return false;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; //true for even index level
        while(!q.empty()){
            int qsize = q.size();
            if(flag){
                int temp1 = -1;
                while(qsize--){ //EVEN level (values must be ODD ans strictly increasing)
                    TreeNode* f = q.front();
                    q.pop();
                    if(f->val <= temp1 || f->val%2 == 0) return false;
                    temp1 = f->val;
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
            }
            if(!flag){ //ODD level (values must be even and strictly decreasing)
                int temp2 = INT_MAX;
                while(qsize--){
                    TreeNode* f = q.front();
                    q.pop();
                    if(f->val >= temp2 || f->val%2 != 0) return false;
                    temp2 = f->val;
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
            }
            flag = !flag;
        }
        return true; 
    }
};
