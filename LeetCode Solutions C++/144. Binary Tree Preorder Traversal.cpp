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
     void preOrder(TreeNode *root, vector<int>& answer){
        if(root == NULL)
            return;

        answer.push_back(root->val);
         
        if(root->left!=nullptr)
          preOrder(root->left, answer);
        
         
        if(root->right!=nullptr)
          preOrder(root->right, answer);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        preOrder(root, answer);
        return answer;
    }
};
