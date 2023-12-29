class Solution {
    /***********Took hint help***************/
     //optimized
    //time: O(n*n*d)
    int dp[301][11]; //bcz start and d are changing
    int solve_memo(vector<int>& jd, int d, int start, int n){
        
        if(d == 1)
            return *max_element(jd.begin() + start, jd.end());
        if(dp[start][d] != -1)
            return dp[start][d];
        
        int minDiffOfJobSchedule = INT_MAX;
        int diffTaskOfDay = INT_MIN; //bcz it has to be max
        
        for(int i=start; i<=n-d; i++){
            diffTaskOfDay = max(diffTaskOfDay, jd[i]);
            minDiffOfJobSchedule = min(minDiffOfJobSchedule, diffTaskOfDay + solve_memo(jd, d-1, i+1, n));
        }
        dp[start][d] = minDiffOfJobSchedule;
        return dp[start][d];
    }
    
    int solve_memoHelper(vector<int>& jd, int d){
        int n = jd.size();
        memset(dp, -1, sizeof(dp));
        return solve_memo(jd, d, 0, n);
        
    }
    
    
    /****************************/
    
    /************Took hint help************/
    //time: O(not sure) ==> TLE have repeated calls
    //time Complexity: for *max_ele..   is O(n),  for loop is O(n) and solve is running O(d-1) ~ O(d)
    int solve(vector<int>& jd, int d, int start, int n){
        
        if(d == 1)
            return *max_element(jd.begin() + start, jd.end());
        
        int minDiffOfJobSchedule = INT_MAX;
        int diffTaskOfDay = INT_MIN; //bcz it has to be max
        
        for(int i=start; i<=n-d; i++){
            diffTaskOfDay = max(diffTaskOfDay, jd[i]);
            minDiffOfJobSchedule = min(minDiffOfJobSchedule, diffTaskOfDay + solve(jd, d-1, i+1, n));
        }
        return minDiffOfJobSchedule;
    }
    
    /****************************/
    
    /*********My Method, WA*********/
    //time: O(d*n), space: O(1)
    int helper(vector<int>& jd, int d, int start){
        int n = jd.size();
        if(n < d)
            return -1;
        if(d == 1)
            return *max_element(jd.begin() + start, jd.end());
        
        return jd[start] + helper(jd, d-1, start + 1);
        
    }
    int minDifficulty_helper(vector<int>& jd, int d) {
       sort(jd.begin(), jd.end());
       return helper(jd, d, 0);   
    }
    /*****************************/
    
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n < d)
            return -1;
        return solve_memoHelper(jd, d);   
    }
};
