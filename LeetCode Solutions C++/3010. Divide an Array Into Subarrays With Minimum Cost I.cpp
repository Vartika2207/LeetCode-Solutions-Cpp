class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        int sec = *min_element(nums.begin()+1, nums.end()); int idx = min_element(nums.begin()+1, nums.end()) - nums.begin();
        
        int third = 51;
        for(int i=1; i<n; i++) {
            if(i!=idx and nums[i]<third)
                third = nums[i];
        }
        return (first+sec+third);
    }

//short app ------------------------------------------------
        int minimumCost(vector<int>& nums) {
                sort(nums.begin() + 1, nums.end());
                return nums[0] + nums[1] + nums[2];
            }
};
