#include<bits/stdc++.h>
class Solution {
public:
    int helper(vector<int>& nums, unordered_map<int,int>freq, int maxNum ){
        // int n=nums.size();
        int *dp=new int[maxNum+1];
        //dp[i] signifies earning till i element (0<=i<=max element of nums)
        dp[0]=0;
        dp[1]=freq[1];
        for(int i=2;i<=maxNum;i++){
            if(freq.count(i)){
                int deleting_i=dp[i-2] + i*freq[i];
                int not_deleting_i=dp[i-1];
                dp[i]=max(deleting_i, not_deleting_i);
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[maxNum];
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int maxNum=*max_element(nums.begin(),nums.end());
        int ans =helper(nums,freq,maxNum);
        return ans;
    }
};
