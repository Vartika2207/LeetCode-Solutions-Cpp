class Solution {
  //time: O(n)
public:
     string breakPalindrome(string S) {
         int n = S.size();
         
         if(n == 1)
             return "";
         
        for (int i = 0; i < n / 2; ++i) {
            if (S[i] != 'a') {
                S[i] = 'a';
                return S;
            }
        }
        S[n - 1] = 'b';
        return  S;
    }
};
