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
    //time: O(len); space: O(len)
    void leafSequenceDFS(TreeNode* root, vector<int>&leaf_seq){
        //base case
        if(!root)
            return ;
        if(!root->left && !root->right){
            leaf_seq.push_back(root->val);
        }
        leafSequenceDFS(root->left, leaf_seq);
        leafSequenceDFS(root->right, leaf_seq);
    }
    
    bool leafSimilar_helper(TreeNode* root1, TreeNode* root2){
        vector<int> leaf_seq1;
        leafSequenceDFS(root1, leaf_seq1);
        vector<int> leaf_seq2;
        leafSequenceDFS(root2, leaf_seq2);
        return (leaf_seq1 == leaf_seq2);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return leafSimilar_helper(root1, root2);
    }
};
