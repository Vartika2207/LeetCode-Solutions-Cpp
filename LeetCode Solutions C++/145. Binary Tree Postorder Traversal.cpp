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
    
    void postOrder(TreeNode *root, vector<int>& answer){
        if(root == NULL)
            return;

        if(root->left!=nullptr)
          postOrder(root->left, answer);
        
        if(root->right!=nullptr)
          postOrder(root->right, answer);
        
        answer.push_back(root->val);
    }
    
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        postOrder(root, answer);
        return answer;
    }
};
