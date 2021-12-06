class Solution {
public:
    
    /***************************/
    //time: O(n! * n), space: 0(n)
    vector<vector<int>> permute_(vector<int>& nums) {
        if(nums.size()<=1)
            return {nums};
        
        vector<vector<int>>output;
        for(int i=0;i<nums.size();i++){
            vector<int>temp(nums.begin(), nums.end());
            temp.erase(temp.begin()+i);
            
            auto res=permute_(temp);
            
            for(int j=0;j<res.size();j++){
                vector<int>_res=res[j]; //res is vector<vector>>
                _res.insert(_res.begin(), nums[i]);
                output.push_back(_res);
            }
        }
        
        return output;
    }
    
   // refer: https://www.youtube.com/watch?v=1Rox5gt51b0
    /***************************/
    
    
    /**********BACKTRACK**********/
    int n;
    //time: O(n! * n), space: O(1)
    vector<vector<int>>output;
    void helper_backtrack(vector<int>&nums, int index){
        
        if(n<=index){
            output.push_back(nums);
            return;
        }
        
        for(int i=index; i<n; i++){
            swap(nums[i], nums[index]);
            helper_backtrack(nums, index+1);
            swap(nums[i], nums[index]);
         }
       }
   
    vector<vector<int>> permute_backtrack(vector<int>& nums) {
        n=nums.size();
        // vector<int>temp;
        helper_backtrack(nums, 0);
        return output;
    }
    /***************************/
    
    vector<vector<int>> permute(vector<int>& nums){
        return permute_backtrack(nums);
    }
    
    
};
