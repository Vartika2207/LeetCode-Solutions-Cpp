class Solution {
public:
//  O(n^3)
    vector<int> countOfPairs(int n, int x, int y) {x--,y--;
        vector<int> ans(n);
        auto dist = [&](int i, int j) {
            int z = abs(i-j);
            z = min(z, abs(i-x) + 1 + abs(y-j));
            z = min(z, abs(i-y) + 1 + abs(x-j));
            return z;
        };
        for (int k=1; k <=n; k++) {
            for (int i =0; i<n;i++) for (int j=i+1;j<n;j++) if (dist(i,j) == k) ans[k-1]+=2;
        }
        return ans;
    }
};
