class Solution {
public:
    
    //method 1: using a mash map or unordered_map => time O(nlgn), space O(n)
    
    //method 2, time O(n), space O(1)
   /*The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of elements using linear time and constant space*/ 
    int mooreVotingAlgo(vector<int>& nums) {
        int count = 0; 
        int element = 0;
        for(int i=0; i<nums.size(); i++){
            if(count==0)
                element = nums[i];
            if(element == nums[i])
                count+=1;
            else
                count-=1;
        }
        return element;
    }
    
    int majorityElement(vector<int>& nums) {
        return mooreVotingAlgo(nums);
    } 
};
