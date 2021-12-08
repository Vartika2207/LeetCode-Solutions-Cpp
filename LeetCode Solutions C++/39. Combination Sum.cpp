class Solution {
private:
    
    //time:O(2^t * k), 2^t for recursion (t is target) and k is for storing that combination
    //space: O(k * x), depends on combinations
    void helper(vector<int>& candidates, int target, int index, vector<int>&temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        else if(index==candidates.size()){
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            helper(candidates, target-candidates[index], index, temp, ans);
            temp.pop_back();
        }
        helper(candidates, target, index+1, temp, ans);
    }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(candidates, target, 0, temp, ans);
        return ans;
    }
};
