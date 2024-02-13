class Solution {
    // app1: reverse -> time:O(n*strlen(i)), space: O(1)
    string firstPalindromeApp1(vector<string>& words) {
        
        for(auto i: words) {
            string j = i;
            reverse(j.begin(), j.end());
            if(j == i)
                return i;
        }
        return "";
    }

    // app2: two pointer -> time:O(n*strlen(i)), space: O(1)
    string firstPalindromeApp2(vector<string>& words) {
        for(auto i: words) {
            int s = 0, e = i.size() - 1;
            bool isPal = true;
            while(s < e) {
                if(i[s] != i[e]) {
                    isPal = false;
                    break;
                }
                else {
                    s++; e--;
                }
            }
            if(isPal)
                return i;
            
        }
        return "";
    }
public:
    string firstPalindrome(vector<string>& words) {
        return firstPalindromeApp1(words);
    }
};
