//time: O(n), space: O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
    
        stack<int> pushStack;
        
        int j=0;
        for(int i=0; i<n ;i++) {
            pushStack.push(pushed[i]);
            
            while(!pushStack.empty() && j<n && pushStack.top() == popped[j]) {
                pushStack.pop();
                j++;
            }
        }
        
        return (j == n);
    }
};
