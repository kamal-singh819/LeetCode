/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean postOrderTraversal(TreeNode root) {
        if(root.val == 0 || root.val == 1) return root.val == 1;
        if(root.val == 2) return postOrderTraversal(root.left) || postOrderTraversal(root.right);
        return postOrderTraversal(root.left) && postOrderTraversal(root.right);
    }
    public boolean evaluateTree(TreeNode root) {
        return  postOrderTraversal(root);
    }
}