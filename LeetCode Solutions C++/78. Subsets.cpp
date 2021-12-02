class Solution {
public:

    int k,n;
    vector<vector<int>>ans;
    
    void helper(vector<int>&nums, vector<int>&temp, int index)
    {
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<n;i++){
            temp.push_back(nums[i]);
            helper(nums, temp, i+1);
            temp.pop_back();
        } 
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        
        for(k=0;k<=n;k++)
           helper(nums, temp, 0);
        
        return ans;
        
        
    }
};
