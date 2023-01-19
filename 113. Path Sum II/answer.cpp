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
    void recursionFunction(TreeNode* root, int &targetSum, vector<int> route, int routeSum,  vector<vector<int>> &ans){
        if(root == NULL)
            return;

        route.push_back(root->val);
        routeSum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(routeSum == targetSum)
                ans.push_back(route);
                return;
        }  

        if(root->left)
            recursionFunction(root->left, targetSum, route, routeSum, ans); 
        if(root->right)
            recursionFunction(root->right, targetSum, route, routeSum, ans);     
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> route; //to store the path
        int routeSum = 0;  //store the sum of path

        recursionFunction(root, targetSum, route, routeSum, ans);

        return ans;    
    }
};
