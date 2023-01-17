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

//we can solve it using level order traversal-----------------------------------------
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {

        if(root->left == NULL && root->right == NULL)
            return root->val;
        int ans = 0;
        vector<int> last;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> vec;
            int siz = q.size();
            while(siz--){
                TreeNode* temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            last = vec;
        }
        for(int i=0; i<last.size(); i++){
            ans += last[i];
        }
        return ans;
    }
};
