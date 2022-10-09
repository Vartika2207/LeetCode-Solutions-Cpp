//time: O(n+n), space: O(n)
class Solution {
    //below is recursive approach
    void findInorderRec(TreeNode* root, vector<int>& inOrder){
        if(!root)
            return;
        
        findInorderRec(root->left, inOrder);
        inOrder.push_back(root->val);
        findInorderRec(root->right, inOrder);
    }
    
    //below is iterative approach
    void findInorderItr(TreeNode* root, vector<int>& inOrder){
        if(!root)
            return;
        
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(true){
            if(temp){
                st.push(temp);
                temp = temp->left;
            }
            else{
                if(st.empty()) break;
                temp = st.top();
                st.pop();
                inOrder.push_back(temp->val);
                temp = temp->right;
            }
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        findInorderItr(root, inOrder);
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
