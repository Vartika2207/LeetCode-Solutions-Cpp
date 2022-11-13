class Solution {
public:
  //space: O(n), time: O(n)
    string reverseWords(string s) {
        vector<string> rev;
        stringstream ss(s);
        string temp;
        while(ss >> temp)
            rev.push_back(temp);
        
       //copying in string
        string rev_string;
        int n = rev.size();
        for(int i = n-1; i>=0; i--){
            rev_string += rev[i];
            if(i != 0)
              rev_string += " ";
        }
        
        return rev_string;
    }
};
