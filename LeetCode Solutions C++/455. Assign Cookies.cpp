class Solution {
    private:
    // approach 1: time: O(n⋅logn+m⋅logm)
    int findContentChildrenNaive(vector<int>& g, vector<int>& s) {
        int g_size = g.size(), s_size = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        int count = 0;
        while(gi < g_size and si < s_size) {
            if(g[gi] <=s[si]) {
                count++;
                gi++; si++;
            }
            else {
                si++;
            }
        }
        cout << gi;
        return count;
    }

    // appraoch 2: binary search i.e. searching g[i] in sorted s-array and removing if found a perfect  cookie
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        return findContentChildrenNaive(g, s);
    }
};
