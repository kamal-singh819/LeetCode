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
    TreeNode* solveFunction(vector<int>& inorder, vector<int>& postorder, int &index, int start, int end, int n){
        if(start > end || index < 0)
            return NULL;

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = inorderIndex[element];
        
        root->right = solveFunction(inorder, postorder, index, position+1, end, n); //pahle right ko call karenge beacuse split karne ke baad jo index mil raha hai wo right wale part me hai...
        root->left = solveFunction(inorder, postorder, index, start, position-1, n);    

        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inorderIndex[inorder[i]] = i;
        }

        int index = n-1; //index of root(last element of postorder will be the root of tree)
        TreeNode* ans = solveFunction(inorder, postorder, index, 0, n-1, n);
        return ans;    
    }
};
