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
    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        //for(int i=0; i<inorder.size(); i++) cout<<inorder[i]<<" ";
        int siz = inorder.size();
        int n = queries.size();
        int m = 2;////
        vector<vector<int>> ans(n, vector<int> (m, -1));
        for(int i=0; i<n; i++){
            int mini = lower_bound(inorder.begin(), inorder.end(), queries[i]) - inorder.begin();
            if(mini >= siz) ans[i][0] = inorder[mini-1];
            else if(mini < siz && mini-1 >= 0 && inorder[mini] > queries[i]) ans[i][0] = inorder[mini-1];
            else if(mini < siz && inorder[mini] == queries[i]) ans[i][0] = inorder[mini];

            int maxi = lower_bound(inorder.begin(), inorder.end(), queries[i]) - inorder.begin();
            if(maxi < siz) ans[i][1] = inorder[maxi];
        }
        return ans;
    }
};
