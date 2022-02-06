lass Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val==val) return root;
        if(root->val > val){
            return searchBST(root->left,val);
        }
        else if(root->val < val){
            return searchBST(root->right,val);
        }
        return 0;
    }
};
