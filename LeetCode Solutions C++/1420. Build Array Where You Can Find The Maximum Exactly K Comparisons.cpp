class Solution {
    const int mod = 1e9+7;
    int numOfArrays_memo_helper(int n, int m, int k, int ***dp, int idx_in_arr, int arr_max_soFar) {
        // arr <= m; size == n; searchCost == k
        if(idx_in_arr == n)
            return k == 0 ? 1 : 0; //can't put more elemts in arr and now k is exausted

        if(k < 0)
            return 0;

        if(dp[idx_in_arr][arr_max_soFar][k] != -1)
            return dp[idx_in_arr][arr_max_soFar][k];

        int answer = 0;
        // case like k=1;m=3;n=2 => [1,1].. jst put 1s(all elements as maxSoFar) to fill arr till n-size
        for(int num=1; num<=arr_max_soFar; num++) {
            answer = (answer + numOfArrays_memo_helper(n, m, k, dp, idx_in_arr+1, arr_max_soFar)) % mod;
        }

        // case [3,2] -- we got max not filling array with (arr_max-1 to 1) till n-size
        for(int num = arr_max_soFar+1; num<=m; num++) {
            answer = (answer + numOfArrays_memo_helper(n, m, k-1, dp, idx_in_arr+1, num)) % mod;
        }
        dp[idx_in_arr][arr_max_soFar][k] = answer;
        return answer;

    }
    int numOfArrays_memo(int n, int m, int k) {
        int ***dp = new int**[n];
        for(int i=0; i<n; i++) {
            dp[i] = new int*[m+1];
            for(int j=0; j<=m; j++){
                dp[i][j] = new int[k+1];
                for(int l=0; l<=k; l++)
                   dp[i][j][l] = -1;
            }
        }

        return numOfArrays_memo_helper(n, m, k, dp, 0, 0);
    } 

public:
    int numOfArrays(int n, int m, int k) {
        return numOfArrays_memo(n,m,k);
    }
};
