class Solution {
public:
  //time: O(n), space: O(n)
    bool isValid(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++){
            if(str[i]==')'){
                if(!s.empty() && s.top()=='(')
                    s.pop();
                else return false; 
            }
            else if(str[i]==']'){
                if(!s.empty() && s.top()=='[')
                    s.pop();
                else return false;
            }
            else if(str[i]=='}'){
                if(!s.empty() && s.top()=='{')
                    s.pop();
                else return false; 
            }
            else s.push(str[i]);
        }
        if(s.empty()) return 1;
        return 0;
    }
};
