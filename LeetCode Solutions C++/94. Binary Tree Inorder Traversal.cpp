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
     void InOrder(TreeNode *root, vector<int>& answer){
        if(root == NULL)
            return;

        if(root->left!=nullptr)
          InOrder(root->left, answer);
        
          answer.push_back(root->val);
         
        if(root->right!=nullptr)
          InOrder(root->right, answer);
    }
    
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        InOrder(root, answer);
        return answer;
    }
};
