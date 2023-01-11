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

///////////////////////////I HAVE SOLVED THIS USING LEVEL ORDER TRAVERSAL OF A TREE///////////////////////////////
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sizQ = q.size();
            vector<int> temp;
            while(sizQ--){
                TreeNode* tp = q.front();
                q.pop();
                temp.push_back(tp->val);
                if(tp->left)
                    q.push(tp->left);
                if(tp->right)
                    q.push(tp->right);    

            }
            levelOrder.push_back(temp);
        }
        int levels = levelOrder.size();
        return levelOrder[levels-1][0];
        
    }
};
