int memo[101][27][101][101]; 
class Solution {
    
    string compressString(string s) {
            string ans;
            int n=s.size();
            int count = 0; string currChar;
            for(int i=0; i<n; i++) {
                if(i > 0 and s[i-1] != s[i]) {
                    // ans += (s[i-1] + count==1?"":to_string(count)); same is mentioned below
                    ans += s[i-1];
                    if(count > 1)
                        ans += to_string(count);
                    
                    cout << ans <<endl;
                    count = 1;
                }
                else {
                    currChar = s[i];
                    count++;
                }
            }
            
            ans += s[n-1];  // ans += (s[n-1] + count==1?"":to_string(count));
            if(count > 1)
                ans += to_string(count);
            return ans;
    }

// approach1: recusrion => time: O(2^n).
    int compress(string s, int idx, int prev, int len, int k) {
        if(k < 0)
            return INT_MAX;
        if(idx >= s.size())
            return 0;

        //case 1 to remove the char
        int removeChar = compress(s, idx+1, prev, len, k-1);

        // case2 to keep the char
        int notRemoveChar = 0;
        if(prev == s[idx]-'a') {
            int increase = 0;
            if(len == 1 || len == 9 || len == 99)
                increase++;
            notRemoveChar = increase + compress(s, idx+1, prev, len+1, k); //len+1 bcz we got same char again
        }
        else {  //here we encounted diff char hence compression-len will inc
            notRemoveChar = 1 + compress(s, idx+1, s[idx]-'a', 1, k); // len is 1 here bcz a new char came 
        }
        return min(removeChar, notRemoveChar);

    }
    int strCompressionRecursion(string s, int k) {
        return compress(s, 0, 26, 0, k);
    }

// approach2: memoization => time: O(n⋅27⋅101⋅101⋅k)
    string s;
    int compressMemo(int idx, int prev, int len, int k) {
        if(k < 0)
            return INT_MAX;
        if (idx >= s.size())
            return (k >= 0) ? 0 : INT_MAX;
        if(memo[idx][prev][len][k] != -1)
            return memo[idx][prev][len][k];

        //case 1 to remove the char
        int removeChar = compressMemo(idx+1, prev, len, k-1);

        // case2 to keep the char
        int notRemoveChar = 0;
        if(prev == s[idx] - 'a') {
            int increase = 0;
            if(len == 1 || len == 9 || len == 99)
                increase++;
            notRemoveChar = increase + compressMemo(idx+1, prev, len+1, k); //len+1 bcz we got same char again
        }
        else {  //here we encounted diff char hence compression-len will inc
            notRemoveChar = 1 + compressMemo(idx+1, s[idx] - 'a', 1, k); // len is 1 here bcz a new char came 
        }
        memo[idx][prev][len][k] = min(removeChar, notRemoveChar);
        return memo[idx][prev][len][k];
    }
    int strCompressionMemo(string str, int k) {
        // int memo[101][27][101][101]; // = {-1};
        memset(memo, -1, sizeof(memo));
        s = str;
        return compressMemo(0, 26, 0, k);
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        return strCompressionMemo(s, k);
    }
};
