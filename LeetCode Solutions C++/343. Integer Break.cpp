class Solution {

int integerBreak_naive(int n) {
    if(n <= 3)
       return n-1; //if n==2 => return 1*1= 1;  if n==3 => return 2*1=2

       int count = 0;
       for(int i=1; i<=n/2; i++) {
           int two_split = i * (n-i);
           int rec_count = integerBreak_naive(n - i);

           count = max({count, two_split, rec_count * i});
       }
       return count;
}

/******************************/
//time: O(n^2) bcz this runs T(n) = n + (n-1) + (n-2) + .. + 1 = N^2
//space: O(n), memo array
int memoHelper(int n, int *memo) {
    if(n <= 3)
       return n-1; //if n==2 => return 1*1= 1;  if n==3 => return 2*1=2

    if(memo[n] != -1)
        return memo[n];

       int count = 0;
       for(int i=1; i<=n/2; i++) {
           int two_split = i * (n-i);
           int rec_count = memoHelper(n - i, memo);

           count = max({count, two_split, rec_count * i});
       }
       memo[n] = count;
       return count;
}

int integerBreak_memo(int n) {
    if(n <= 3)
       return n-1; //if n==2 => return 1*1= 1;  if n==3 => return 2*1=2

    int *memo = new int[n+1]();
    memo[2] = 1; memo[3] = 2;
    for(int i=4; i<=n; i++) {
        memo[i] = -1;
    }

    int break_product =  memoHelper(n, memo);

    //free space
    delete[] memo;

    return break_product;
}

/****************************/
//time: O(n^2) we iterate from i=2 until num, i.e. (num = 4 to n)* (2 to num) = O(n^2)
int integerBreak_dp(int n) {
    if(n <= 3)
       return n-1; //if n==2 => return 1*1= 1;  if n==3 => return 2*1=2

    int *dp = new int[n+1]();
    dp[2] = 1; dp[3] = 2;

    for(int num=4; num<=n; num++) {
        int answer = num-1;
        for(int i=2; i<num; i++) {
            answer = max({answer, (num-i) * i, dp[num-i] * i});
        }
        dp[num] = answer;
    }

    int ans = dp[n];

    delete[] dp;
    return ans;
}

public:
    int integerBreak(int n) {
        return integerBreak_dp(n);
    }
}; 
