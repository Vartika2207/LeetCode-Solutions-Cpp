class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
     int row=mat.size();
     int col=mat[0].size();
     int maxSqr=INT_MIN;
     if(row==1&&col==1) return (mat[0][0]=='1')?1:0;
        
     int **dp=new int*[row];
        for(int i=0;i<row;i++){
            dp[i]=new int[col];
            for(int j=0;j<col;j++){
                dp[i][j]=0;
            }
        }
        //first col
        for(int i=0;i<row;i++){
            if(mat[i][0]=='1')
               dp[i][0]=1;
            maxSqr=max(maxSqr,dp[i][0]);
        }
        //first row
        for(int i=0;i<col;i++){
            if(mat[0][i]=='1')
               dp[0][i]=1;
            maxSqr=max(maxSqr,dp[0][i]);
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(mat[i][j]=='1'){
                dp[i][j]=min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1;
                maxSqr=max(maxSqr, dp[i][j]);
                }
            }
        }
        
        return pow(maxSqr,2);
    }
};
