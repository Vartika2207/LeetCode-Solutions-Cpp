class Solution {
public:
   
    //dp: Time=>O(n)
    int climbStairs(int n){
       
        int *dp=new int [n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }
        int ans= dp[n];
        delete[] dp;
        return ans;
    }
     //Recursion: TLE Time=>O(2^n)
    int climbStairsRec(int n) {
        if(n==0) return 1;
        if(n==1 ) return 1;
        int ans=(long)(climbStairs(n-1) + climbStairs(n-2));     
        return ans;
    }
   
};

/*
 int helperMemo(int n, vector<int>&dp){
        if(n==0){
            dp[0]=1; return 1;
        }
        if(n==1){
            dp[1]=1; return 1;
        }
        if(dp[n]!=-1) return dp[n];
        dp[n]=dp[n-2]+dp[n-1];
        return dp[n];
    }
    
    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        int ans=helperMemo(n,dp);
        return ans;
    }
    
    
*/
