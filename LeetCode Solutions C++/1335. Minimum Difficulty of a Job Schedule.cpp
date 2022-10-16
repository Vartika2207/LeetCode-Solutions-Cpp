class Solution {
    /************Took hint help************/
    //time: O(n*n*d) ==> TLE
    //time Complexity: for *max_ele..   is O(n),  for loop is O(n) and solve is running O(d-1) ~ O(d)
    int solve(vector<int>& jd, int d, int start){
        int n = jd.size();
        if(n < d)
            return -1;
        
        if(d == 1)
            return *max_element(jd.begin() + start, jd.end());
        
        int minDiffOfJobSchedule = INT_MAX;
        int diffTaskOfDay = INT_MIN; //bcz it has to be max
        
        for(int i=start; i<=n-d; i++){
            diffTaskOfDay = max(diffTaskOfDay, jd[i]);
            minDiffOfJobSchedule = min(minDiffOfJobSchedule, diffTaskOfDay + solve(jd, d-1, i+1));
        }
        return minDiffOfJobSchedule;
    }
    
    
    /****************************/
    
    /*********My Method, giving WA*********/
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
       return solve(jd, d, 0);   
    }
};
