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
    int left, right;
    int ll, lr, rl, rr;
    int move(TreeNode root ){
        if(root == null)
            return 0;
        ll = 0; lr = 0;
        rl = 0; rr  =0;
        left = move(root.left);
        right = move(root.right);
        
        return Math.max(root.val + ll + lr + rl + rr, left + right);
    }
    
    public int rob(TreeNode root) {
         left = 0; right = 0;
        return move(root);
    }
}
