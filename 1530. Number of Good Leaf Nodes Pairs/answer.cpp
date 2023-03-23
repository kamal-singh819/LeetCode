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
    vector<int> function(TreeNode* root, int d, int &ans){
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {1};

        vector<int> leftCall = function(root->left, d, ans);
        vector<int> rightCall = function(root->right, d, ans);
        //now make pair 
        for(int a : leftCall){
            for(int b : rightCall){
                if(a+b <= d) ans++;
            }
        }
        //now return vector to root
        vector<int> rt;
        for(int a : leftCall){
            if(a+1 < d) rt.push_back(a+1); //if any distance will be greater than d, no need to put it into rt vector//(Optional)
        }
        for(int a : rightCall){
            if(a+1 < d) rt.push_back(a+1);
        }

        //finally return rt to root
        return rt;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        //use postorder DFS
        function(root, distance, ans);
        return ans;
    }
};
