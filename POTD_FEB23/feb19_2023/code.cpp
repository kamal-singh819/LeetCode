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

#include<queue>
class Solution {
private:
    vector<int> reverse(vector<int> &ans){
        int i=0;
        int j=ans.size()-1;
        while(i <= j){
            swap(ans[i], ans[j]);
            i++;
            j--;
        }
        return ans;
    }    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int siz = q.size();
            vector<int> ans;
            while(siz--){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            if(flag == true)
                result.push_back(ans);
            else{
                result.push_back(reverse(ans));
            }
            flag = !flag;    
        } 
        return result;   
        
    }
};
