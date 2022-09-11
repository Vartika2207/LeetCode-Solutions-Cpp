//time: O(n!); space: O(n*n)
class Solution {
    vector<vector<string>> result;
    bool is_valid(int n, vector<string>& grid, int& row, int col){
        //check isValid in vertically
        for(int i=row; i>=0; i--){
            if(grid[i][col] == 'Q')
                return false;
        }
        
         //check isValid in left-up diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(grid[i][j] == 'Q')
                return false;
        }
        
        //check isValid in right-up diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(grid[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    
    
    void solveNQueens_helper(int n, vector<string>& grid, int row){
        if(row == n){
            //outof grid
            result.push_back(grid);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(is_valid(n, grid, row, i)){
                grid[row][i] = 'Q';
                solveNQueens_helper(n, grid, row+1);
                grid[row][i] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens_(int n) {
        vector<string> grid(n, string(n, '.'));
        solveNQueens_helper(n, grid, 0);
        return result;
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        return solveNQueens_(n);
    }
};
