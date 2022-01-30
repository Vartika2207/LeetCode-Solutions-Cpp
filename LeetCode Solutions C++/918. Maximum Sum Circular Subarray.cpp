class Solution {
    
    int kadane(vector<int> &nums, int sign){
        int curr_sum = INT_MIN, max_sum = INT_MIN;
        
        for(auto i: nums){
            curr_sum = sign*i + max(curr_sum, 0);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int sum_of_array = accumulate(nums.begin(), nums.end(), 0);
        
        int max_sum_subarray = kadane(nums, 1);
        int min_sum_subarray = kadane(nums, -1)*-1; 
        
        if(sum_of_array == min_sum_subarray)
            return max_sum_subarray;
        else
            return max(max_sum_subarray, sum_of_array - min_sum_subarray);
    }
};
