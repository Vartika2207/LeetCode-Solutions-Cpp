class Solution {
public:
    
    /*************Approach-4, DP =>Accepted***************/ 
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
    
    bool canPartitionDP(vector<int>&nums){
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0 ) return false;
        return helperDP(nums,totalSum/2); //if we can find one subset, we will always get two subset then
    }
    /********************************************************/
    
    
    
    /*************Approach-3, Memoization =>Accepted***************/ 
    //time: O(n*sum)
   bool helperMemo(vector<int>&nums, int index, int sumOfSubset, int **memo){
       
        if(sumOfSubset == 0) 
            return true;
       
       if(index >= nums.size() || sumOfSubset < 0)
           return false;
        
       if(memo[index][sumOfSubset] != -1)
           return memo[index][sumOfSubset];
        
       int chosen = helperMemo(nums, index+1, sumOfSubset - nums[index], memo);
       int not_chosen = helperMemo(nums, index+1, sumOfSubset, memo);
        
       memo[index][sumOfSubset] = chosen || not_chosen;
       return memo[index][sumOfSubset];
    }
    
    bool canPartitionMemo(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0 ) return false;
        
        int **memo = new int*[nums.size()+1];
        for(int i=0; i<=nums.size(); i++){
            memo[i] = new int[totalSum/2+1];
            for(int j=0; j<=totalSum/2; j++){
                memo[i][j] = -1;
            }
        }
        
        return helperMemo(nums,0,totalSum/2, memo);

    }
    /********************************************************/
    
    
    /*************Approach-2, Better recursion =>TLE***************/ 
    //time: O(2^n)
    //tle using recursion
    bool helperRec_better(vector<int>&nums, int index, int sum){
        if(index >= size(nums) || sum < 0)
            return false;
        
        if(sum == 0)
            return true;
        
        int chosen = helperRec_better(nums, index+1, sum - nums[index]);
        int not_chosen = helperRec_better(nums, index+1, sum);
        return chosen || not_chosen;
    }
    
    bool canPartitionRec_better(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0 ) return false;
        return helperRec_better(nums,0,totalSum/2);

    }
    /************************************************************/
    
    
    
   /*************Approach-1, Brute-force =>TLE***************/ 
    //time: O(2^n)
    //tle using recursion
    bool helperRec(vector<int>&nums, int startingIndex, int currentSubsetSum, int sumOfSubset, int k){
        if(k==1) return true; //found on subset then other will definately be present;
        
        if(currentSubsetSum == sumOfSubset) 
            return true;
        if(currentSubsetSum > sumOfSubset) return false;
        
        for(int i=startingIndex;i<nums.size();i++){
            int chosen = helperRec(nums, i+1, currentSubsetSum+nums[i], sumOfSubset, k);
            int notChosen = helperRec(nums, i+1, currentSubsetSum, sumOfSubset, k);
            return chosen || notChosen;
        }
        return false;
    }
    
    bool canPartitionRec(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2!=0 ) return false;
        return helperRec(nums,0,0,totalSum/2,2);

    }
    /************************************************************/
    
    bool canPartition(vector<int>& nums) {
        return canPartitionRec_better(nums);
    }
    
    
};
