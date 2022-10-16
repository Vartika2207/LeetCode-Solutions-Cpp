class Solution {
public:
   //time: O(nm), space: O(nm)
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int **dp = new int*[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = new int[m+1]();
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = 0;
                
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
