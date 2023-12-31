class Solution {
private:
// approach1: do search in O(n*n) and check 2 equal char and find len in b/t

// approach2: using map=> time: O(n), space: O(n)
    int maxLenBtwNaive(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxLenBtw = -1;
        for(int i=0; i<n; i++) {
            if(mp.count(s[i])) 
                maxLenBtw = max(maxLenBtw, i - mp[s[i]] - 1);
            else
                mp[s[i]] = i;
        }
        return maxLenBtw;
}
public:
    int maxLengthBetweenEqualCharacters(string s) {
        return maxLenBtwNaive(s);;
    }
};
