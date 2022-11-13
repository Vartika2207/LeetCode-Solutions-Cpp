class Solution {
public:
    //time: O(n), space: O(n)
    string reverseWords_naive(string s) {
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
    
    //time: O(n), space: O(1)
    string reverseWords_better(string s){
        reverse(s.begin(), s.end());
        
        int l = 0, r = 0, i = 0, n = s.size();
        while(i < n){
            while(i < n && s[i] != ' ')
                s[r++] = s[i++];
            
            if(r > l){ //word found in string
                reverse(s.begin() + l, s.begin() + r);
                
                if(r == n) //end of string
                    break;
                s[r] = ' '; r++;
                l = r;
            }
            i++; //s[i] =' ', skip this
        }
        if(r > 0 and s[r-1] == ' '){ //skip last character
            r--;
            s.resize(r);
        }
        return s;
    }
    
    string reverseWords(string s){
        return reverseWords_better(s);
    }
};
