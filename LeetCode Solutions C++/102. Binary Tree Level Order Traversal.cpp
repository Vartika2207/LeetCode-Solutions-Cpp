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
      vector<vector<int>> levelOrder(TreeNode* root) {
            if(root==NULL) return {};
          
            vector<vector<int>> ans; 
         
            queue<TreeNode*> pNodes;
            pNodes.push(root);
          
            while(!pNodes.empty()){
                int size=pNodes.size();
                vector<int>levels;
                while(size--){
                TreeNode*front=pNodes.front();
                pNodes.pop();
                levels.push_back(front->val);
                if(front->left!=NULL ) pNodes.push(front->left); 
                if(front->right!=NULL )pNodes.push(front->right);
            }
                ans.push_back(levels);
           }
            return ans;

    }
};
