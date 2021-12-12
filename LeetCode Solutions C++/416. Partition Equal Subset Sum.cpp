class Solution {
public:
    
    /*************Approach-2, DP =>Accepted***************/ 
    //time: O(n*sum)
    bool helperDP(vector<int>&nums, int sumOfSubset){
        vector<bool>dp(sumOfSubset+1,false); 
        //dp[i] represent chance possibility to get i sum
        dp[0]=true;    //we can always get subset having 0 sum
        for(int num : nums){
            for(int sum=sumOfSubset; sum>=num; sum--){
                dp[sum] = dp[sum] || dp[sum-num];
            }
        }
        return dp[sumOfSubset];
        
    }
    
    bool canPartition(vector<int>&nums){
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0 ) return false;
        return helperDP(nums,totalSum/2); //if we can find one subset, we will always get two subset then
    }
    /********************************************************/
    
    
   /*************Approach-1, Brute-force =>TLE***************/ 
    //time: O(2^n)
    //tle using recursion
    bool helper(vector<int>&nums, int startingIndex, int currentSubsetSum, int sumOfSubset, int k){
        if(k==1) return true; //found on subset then other will definately be present;
        
        if(currentSubsetSum == sumOfSubset) 
            return true;
        if(currentSubsetSum > sumOfSubset) return false;
        
        for(int i=startingIndex;i<nums.size();i++){
            int chosen = helper(nums, i+1, currentSubsetSum+nums[i], sumOfSubset, k);
            int notChosen = helper(nums, i+1, currentSubsetSum, sumOfSubset, k);
            return chosen || notChosen;
        }
        return false;
    }
    
    bool canPartitionRec(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0 ) return false;
        return helper(nums,0,0,totalSum/2,2);

    }
    /************************************************************/
};
