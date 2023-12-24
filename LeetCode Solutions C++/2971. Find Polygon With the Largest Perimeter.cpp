class Solution {
    // approach 1:    Time: O(n^2)=> using accumulate at every ith indx 
    
    // approach 2:    Time: O(n), 
    long long lp(vector<int>& nums) {
        int n = nums.size();
        long long *prefix = new long long[n]();
        long long perimeter = -1;
        
        sort(nums.begin(), nums.end());
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for(int i=n-1; i>=2; i--) {
            if(nums[i] >= prefix[i-1])
                continue;
            else 
                perimeter = max(perimeter, prefix[i]);
        }
        return perimeter;
    }
    
public:
    long long largestPerimeter(vector<int>& nums) {
        return lp(nums);
    }
};
