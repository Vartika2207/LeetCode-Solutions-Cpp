//time: O(n+n), space: O(n)
class Solution {
  //time:O(n), space: 0(1)
    void findInorder(TreeNode* root, vector<int>& inOrder){
        if(!root)
            return;
        
        findInOrder(root->left, inOrder);
        inOrder.push_back(root->val);
        findInOrder(root->right, inOrder);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        findInorder(root, inOrder);
        int start = 0, end = inOrder.size() - 1;
        while(start < end){
            int sum = inOrder[start] + inOrder[end];
            if(sum == k)
                return true;
            if(sum > k)
                end--;
            else
                start++;
        }
        return false;
    }
};
