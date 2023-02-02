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
    unordered_map<int, int> inorderIndex;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end, int &n){
        if(start > end || index >= n)
            return NULL;

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = inorderIndex[element]; 

        root->left = solve(preorder, inorder, index, start, position-1, n);
        root->right = solve(preorder, inorder, index, position+1, end, n);

        return root;   

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(); //size of array
        for(int i=0; i<n; i++){
            inorderIndex[inorder[i]] = i;
        }

        int index = 0; //root index(first element of preorder will be the root of tree)

        TreeNode* ans = solve(preorder, inorder, index, 0, n-1, n);

        return ans;
        
    }
};
