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
  //time: O(nodes), space: O(height)
    int mod = 1e9+7;
    long productMax = 0, treeSum = 0;
    int sumTree(TreeNode* root){
        if(!root)
            return 0;
        
        long sum = root->val + sumTree(root->left) + sumTree(root->right);
        productMax = max(productMax, (treeSum - sum)*sum);
        return sum;
    }
    
    int maxProduct_rec(TreeNode* root){
        treeSum = sumTree(root);
        sumTree(root);
        return (productMax % (int)mod);
    }
    
public:
    int maxProduct(TreeNode* root) {
        return maxProduct_rec(root)%mod;
    }
    
};






