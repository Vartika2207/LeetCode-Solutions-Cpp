class Solution {
public:
    
    //unsing dp
     int helperDP(int n, vector<int>dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
    
     int tribonacci(int n){
         vector<int>dp(n+1);
         return helperDP(n,dp);
     }
    
    //memo
    int helperMemo(int n, vector<int> dp){
        if(n==0){
            dp[0]=0; return 0;
        }
        if(n==1 || n==2){
            dp[n]=1; return dp[n];
        }
        if(dp[n]!=-1) return dp[n];
        if(dp[n-3]==-1)  dp[n-3] = helperMemo(n-3,dp);
        if(dp[n-2]==-1)  dp[n-2] = helperMemo(n-2,dp);
        if(dp[n-1]==-1)  dp[n-1] = helperMemo(n-1,dp);
        return dp[n-1] + dp[n-2] + dp[n-3];   
    }
   
    int tribonacci(int n){
        vector<int>dp(n+1,-1);
        return helperMemo(n,dp);
    }
    
    //using rec
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
    
};
