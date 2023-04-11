class Solution {
public:
    //time: O(n), space: O(n)
    string removeStars_stack(string s) {
        stack<char> st;
        
        for(char c: s) {
            if(!st.empty() && c == '*') {
                st.pop();
            }
            else
                st.push(c);
        }
        
        string answer = "";
        while(!st.empty()) {
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
    //time: O(n), space: O(1)
    string removeStars_string(string str) {
        string answer = "";
        for(char c: str) {
            if(c == '*') {
                answer.pop_back();
            }
            else {
                answer.push_back(c);
            }
        }
        return answer;
    }
    
    string removeStars(string s) {
        return removeStars_string(s);
    }
};
