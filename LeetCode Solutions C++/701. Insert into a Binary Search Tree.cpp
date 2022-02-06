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
    //time: O(height)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *head = new TreeNode(val);
            return head;
        }
        TreeNode *temp_root = root;
        if(val < root->val){
           root->left = insertIntoBST(root->left, val);
        }
        else if((val > root->val)){
           root->right = insertIntoBST(root->right, val);
        }
        return temp_root;
        
    }
};
