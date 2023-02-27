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
private:
    void dfs(TreeNode* root, string str, vector<string> &ans){
        if(root == NULL) return;

        else if(root->left == NULL && root->right == NULL){
            str += to_string(root->val);
            ans.push_back(str);
            return;
        }
        str += to_string(root->val);
        str += "->";
        dfs(root->left, str, ans);
        dfs(root->right, str, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = "";
        dfs(root, str, ans);

        return ans;
        
    }
};
