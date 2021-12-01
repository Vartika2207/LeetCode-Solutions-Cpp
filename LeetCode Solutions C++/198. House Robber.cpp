class Solution {
public:
    /*********DP - approach************/
    //time: O(n)
    int rob(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        int *dp=new int[nums.size()];
        dp[0]=nums[0]; 
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2] + nums[i] , dp[i-1]);
        }
        int ans= dp[n-1];
        delete[] dp;
        return ans;
    }
    
    
    /*************BRUTE*******************/
    //using recursion
    //time: O(2^n)
    int helper(vector<int>&nums, int n, int s){
        if(s==n-1) return nums[s];
        if(s>=n) return 0;
        
        int robbed=helper(nums,n,s+2) + nums[s];
        int not_robbed=helper(nums,n,s+1); 
        
        return max(robbed, not_robbed);
    }
    
    int robRec(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,n,0);
    }
};
