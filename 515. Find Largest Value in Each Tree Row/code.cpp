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

////////////////////////////////////////THIS QUESTION IS SOLVED USING LEVEL ORDER TRAVERSAL//////////////////////////////
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sizQ = q.size();
            int x = INT_MIN; //store maximum value in each row
            while(sizQ--){
                TreeNode* temp = q.front();
                q.pop();
                x = max(x, temp->val); //CHECKING MAXIMUM
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            ans.push_back(x);
        }
        return ans;
        
    }
};
