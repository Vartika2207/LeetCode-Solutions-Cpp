#define maxVal 99999
class Solution {
public:
    
    //dp
    int minPathSum(vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        int **dp=new int*[row];
        for(int i=0;i<row;i++){
            dp[i]=new int[col];
            for(int j=0;j<col;j++){
                dp[i][j]=maxVal;
            }
        }
        
        dp[row-1][col-1]=grid[row-1][col-1];//base
        for(int i=row-2;i>=0;i--){//last col
            dp[i][col-1]=dp[i+1][col-1]+grid[i][col-1];
        }
        for(int i=col-2;i>=0;i--){//last row
            dp[row-1][i]=dp[row-1][i+1] + grid[row-1][i];
        }
        
        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                dp[i][j]=min(dp[i+1][j] , dp[i][j+1]) +grid[i][j];
            }
        }
        
        int ans=dp[0][0];
        //free
        for(int i=0;i<row;i++){
            delete[] dp[i];
        }
        delete[] dp;
        
        //return ans
        return ans;
    }
    
    
    //memoization
    int helperMemo(vector<vector<int>>& grid, int **dp, int row, int col){
        if(row==0 && col==0) {
            dp[row][col]=grid[0][0];
            return grid[0][0];
        }
        if(row<0 || col <0) return maxVal;
        
        if(dp[row][col]!=-1) return dp[row][col];
        int left=helperMemo(grid,dp,row,col-1);
        int down=helperMemo(grid,dp,row-1,col);
        dp[row][col]=min(left,down) + grid[row][col];
            
        return dp[row][col];    
        
    }
    int minPathSumMemo(vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        int **dp=new int*[row];
        for(int i=0;i<row;i++){
            dp[i]=new int[col];
            for(int j=0;j<col;j++){
                dp[i][j]=-1;
            }
        }
        
        
        int ans=helperMemo(grid,dp,row-1,col-1);
 
        //free
        for(int i=0;i<row;i++){
            delete[] dp[i];
        }
        delete[] dp;
        //return ans
        return ans;   
    }
    

    //recursion
    int helper(vector<vector<int>>& grid, int row, int col){
        
        if(row==0 && col==0) return grid[0][0]; //base
        if(row<0 || col<0) return maxVal;
        int left=helper(grid,row,col-1);
        int down=helper(grid,row-1,col);
        return min(left,down)+grid[row][col];
        
        
    }
    int minPathSumRec(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        //base case
        return helper(grid,row-1,col-1);
    }
    

};
