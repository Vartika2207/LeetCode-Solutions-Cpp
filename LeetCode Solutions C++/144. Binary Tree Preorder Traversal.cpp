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
    void preOrder(TreeNode root, List<Integer> answer){
        if(root == null)
            return;

        answer.add(root.val);
         
        if(root.left != null)
          preOrder(root.left, answer);
        
         
        if(root.right != null)
          preOrder(root.right, answer);
    }
    
    
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        preOrder(root, answer);
        return answer;
    }
}
