class Solution {
public:
    bool isSymmetric(TreeNode *root){
        if(root==NULL) return true;
        return isSameTree(root->left,root->right);
    }
    bool isSameTree(TreeNode* root1,TreeNode *root2) {
    
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL && root2!=NULL || root1!=NULL && root2==NULL) return false;
        if(root1->val!=root2->val) return false;
        return isSameTree(root1->left,root2->right) && isSameTree(root1->right,root2->left);
    }
};
