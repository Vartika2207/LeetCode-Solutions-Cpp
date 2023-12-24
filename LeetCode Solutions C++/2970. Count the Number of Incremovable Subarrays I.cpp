class Solution {
    int isc(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int isStrictlyInc = 1;
                int lastElement = -1;
                for(int k=0; k<n; k++) {
                    //outside i-j window
                    if(!(k >= i and k <= j)) {
                        isStrictlyInc &= lastElement < nums[k];
                        lastElement = nums[k];
                    }
                }
                count += isStrictlyInc;
            }
        }
        return count;
    }
    
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        return isc(nums);
    }
};
