class Solution {
   
    //time: O(2^n *n), n for putting element into set and 2^ for recusion
    void findSubset(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>> &ans){
        ans.push_back(temp);
        
        for(int i=idx; i<nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            findSubset(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> answer;
        
        findSubset(0, nums, temp, answer);
        return answer;
    }
};
