//time: O(n*n), space: O(2n)
class Solution {
    struct job{
        int start;
        int end;
        int pr;
    };
    
    static bool cmp(job a, job b){
        if(a.end == b.end)
            return a.start < b.start;
        return a.end < b.end;
    }
    
    
    bool noOverLap(int i, int j, job *jobs){
        if(jobs[j].end <= jobs[i].start)
            return true;
        return false;
    }
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        
        job *jobs = new job[n];
        for(int i=0; i<n; i++){
            jobs[i].start = st[i];
            jobs[i].end = et[i];
            jobs[i].pr = profit[i];
        }
        
        sort(jobs, jobs + n, cmp);
        int *dp = new int[n]();
        for(int i=0; i<n; i++){
            dp[i] = jobs[i].pr;
        }
        
        for(int i=1; i<n; i++){
            dp[i] = max(jobs[i].pr, dp[i-1]);
            for(int j=i-1; j >= 0; j--){
                if(noOverLap(i, j, jobs)){
                    dp[i] = max(dp[i], jobs[i].pr + dp[j]);
                    break;
                }
            }
        }
        
        return *max_element(dp, dp+n);
    }
};
