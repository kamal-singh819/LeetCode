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


//WE WILL CALL DFS FOR EVERY NODE...............
class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* root, long long targetSum, long long route){
        if(root == NULL)
            return;
        
        route += root->val;
        if(route == targetSum)
            ans++;

        if(root->left)
            dfs(root->left, targetSum, route);
        if(root->right)    
            dfs(root->right, targetSum, route);        

    }
    int answer(TreeNode* root, long long targetSum){
        if(root == NULL)
            return 0;
        
        long long route = 0;
        dfs(root, targetSum, route); //we will dfs for every Node---------
        if(root->left)
            answer(root->left, targetSum);
        if(root->right)    
            answer(root->right, targetSum);

        return ans;    
    }

//////////////////////////////////////////////////////////////////////////////////////    
    int pathSum(TreeNode* root, int targetSum) {

        return answer(root, (long long)targetSum);
        
    }
};
