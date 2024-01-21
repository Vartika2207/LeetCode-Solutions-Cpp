class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--, y--;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) if (i != j) {
                int dist = min({j - i, abs(i - x) + abs(j - y) + 1, abs(i - y) + abs(j - x) + 1});
                ans[dist - 1] += 2;
            }
        }
        return ans;
    }
};
