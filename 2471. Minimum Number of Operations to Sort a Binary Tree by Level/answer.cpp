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
    int minimumSwap(vector<int> &temp){  //this is a function to find minimum swap required to sort an array...
        int count = 0;
        vector<pair<int, int>> v;

        for(int i=0; i<temp.size(); i++){
            v.push_back(make_pair(temp[i], i));
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            if(i == v[i].second)
                continue;
            else{
                count++;
                swap(v[i], v[v[i].second]);
                i--;
            }    
        }
        return count;
    }
public:
    int minimumOperations(TreeNode* root) { //level order traversal of a tree
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            vector<int> level;
            while(siz--){
                TreeNode* frontt = q.front();
                q.pop();
                level.push_back(frontt->val);
                if(frontt->left)
                    q.push(frontt->left);
                if(frontt->right)
                    q.push(frontt->right);    
            }
            ans += minimumSwap(level);

        }
        return ans;   
    }
};
