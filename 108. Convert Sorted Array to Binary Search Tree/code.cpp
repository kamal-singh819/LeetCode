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
    TreeNode* function(vector<int> &nums, int start, int last){
        int mid = 0;
        if((last-start+1)%2 == 0)
            mid = start + (last-start)/2 + 1;
        else
            mid = start + (last-start)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        if(mid == start) return root; ////////////////base condition V.Imp

        if(start <= mid)
            root->left = function(nums, start, mid-1);
        if(mid+1 <= last)
            root->right = function(nums, mid+1, last);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return function(nums, 0, nums.size()-1);   
    }
};
