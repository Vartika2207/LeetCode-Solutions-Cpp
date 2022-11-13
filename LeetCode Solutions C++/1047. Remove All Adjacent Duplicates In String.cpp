class Solution {
public:
  //time: O(n), space: O(n)
    string removeDuplicates_naive(string s) {
        stack<char> st;
        
        for(auto i: s){
            if(!st.empty() and st.top() == i)
                st.pop();
            else 
                st.push(i);
        }
        
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
  //time: O(n), space: O(1)
    string removeDuplicates_better(string s){
        string ans;
        
        for(auto i: s){
            if(ans.size() && ans.back() == i)
                ans.pop_back();
            else
                ans.push_back(i);
        }
        return ans;
    }
    
    string removeDuplicates(string s) {
        return removeDuplicates_better(s);
    }
};
