class Solution {
public:
    //time: O(n), space: O(1)
    int findMaxConsecutiveOnesBrute(vector<int>& nums){
        int maxCount = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                maxCount = max(count, maxCount);
                count = 0;
            }
            else{
                count++;
            }
        }
        maxCount = max(count, maxCount);
        return maxCount;
    }
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        return findMaxConsecutiveOnesBrute(nums);
    }
};