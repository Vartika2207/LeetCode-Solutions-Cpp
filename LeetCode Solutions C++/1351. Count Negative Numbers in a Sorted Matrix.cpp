class Solution {
//time: O(n+m)
    int countNegativesNaive(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0, row = n-1, col = 0;
        while(row >= 0 and col < m) {
            if(grid[row][col] >= 0) 
                col++;
            else {
                count += (m-col);
                row--;
            }
        }
        return count;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        return countNegativesNaive(grid);
    }
};
