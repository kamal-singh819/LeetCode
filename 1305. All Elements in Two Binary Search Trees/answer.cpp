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
    vector<int> inorder1;  //declare vector globally
    vector<int> inorder2;  //declare vector globally
    vector<int> ans;       //declare vector globally
  
  //INORDER FOR TREE-1
    void inOrderTraversal1(TreeNode* root1){
        if(root1 == NULL)
            return;
        inOrderTraversal1(root1->left);
        inorder1.push_back(root1->val);
        inOrderTraversal1(root1->right);
    }

  
  //INORDER FOR TREE-2
    void inOrderTraversal2(TreeNode* root2){
        if(root2 == NULL)
            return;
        inOrderTraversal2(root2->left);
        inorder2.push_back(root2->val);
        inOrderTraversal2(root2->right);
    }
  
  //MAIN FUNCTION------------------------------------------------------------------
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inOrderTraversal1(root1);
        inOrderTraversal2(root2);

      //NOW MERGE BOTH THE SORTED ARRAYS inorder1 & inorder2 ans store in ans...............
        int i=0;
        int j=0;
        while(i < inorder1.size() && j < inorder2.size()){
            if(inorder1[i] <= inorder2[j]){
                ans.push_back(inorder1[i]);
                i++;
            }
            else if(inorder1[i] >= inorder2[j]){
                ans.push_back(inorder2[j]);
                j++;
            }
        }

        if(inorder1.size() == 0)
            return inorder2;
        if(inorder2.size() == 0)
            return inorder1;   
        while(i < inorder1.size()){
            ans.push_back(inorder1[i]);
            i++;
        }
        while(j < inorder2.size()){
            ans.push_back(inorder2[j]);
            j++;
        }

        return ans;
    }
};
