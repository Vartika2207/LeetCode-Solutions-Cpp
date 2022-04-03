class Solution {
public:
    //time: 0(nlogn)
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=n-3; i >= 0; i--){
            if(nums[i] + nums[i+1] > nums[i+2])
                return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
        
    }
};
