#include <iostream>
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i=0; i<s.size();i++){
            if(s[i] == '6'){
                s.replace(i, 1, "9");
                return stoi(s);
            }
        }
        return stoi(s);
    }
};
