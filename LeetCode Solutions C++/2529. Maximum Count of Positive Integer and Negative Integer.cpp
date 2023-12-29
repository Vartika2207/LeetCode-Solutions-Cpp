class Solution {
    int maximumCountNaive(vector<int>& nums) {
        int n = nums.size(), maxCount = 0, minCount = 0;
        int start = 0, end = n-1;
    
        // count -ve
        while(start <= end) {
            int mid = (start + end)/2;
            if(nums[mid] >= 0) {
                end = mid-1;
            }
            else {
                minCount += (mid - start + 1);
                start = mid+1;
            }
        }

        // count -ve
        start = 0, end = n-1;
        while(start <= end) {
            int mid = (start + end)/2;
            if(nums[mid] <= 0) {
                start = mid + 1;
            }
            else {
                maxCount += (end - mid + 1);
                end = mid - 1;
            }
        }
         return max(minCount, maxCount);
    }

    // approach2
    int maximumCount_usingbound(vector<int>& nums) {
        int negativeCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(); //lb give 1st element lesser to 0
        int positiveCount = nums.end() - upper_bound(nums.begin(), nums.end(), 0); //ub give 1st element greater to 0
        cout << negativeCount<< " "<<positiveCount;
        return max(negativeCount, positiveCount);
    }
public:
    int maximumCount(vector<int>& nums) {
        return maximumCount_usingbound(nums);
    }
};
