class Solution {
public:
    //time: O(2^n * k), 2^n for recursion and k for inserting in vector
    vector<vector<int>> answer;
    
    void combinationSum2_helper(vector<int>& candidates, int target, vector<int>& temp, int index){
        if(target == 0){
            answer.push_back(temp);
            return;
        }
        
        for(int i=index; i< candidates.size(); i++){
             if(i > index && candidates[i] == candidates[i-1])
                continue;
            
            
            if(candidates[index] > target)
                break;
            
            if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            combinationSum2_helper(candidates, target - candidates[i], temp, i+1);   
            temp.pop_back();
       }
        
        }
   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        combinationSum2_helper(candidates, target, temp, 0);
        return answer;
    }
};
