class Solution {

//  time: O(n)
    int singleNonDuplicateXor(vector<int>& nums) {
        int ans = nums[0];
        for(auto i = 1; i< nums.size(); i++)
            ans ^= nums[i];
        return ans;
    }

// time: log(n)
    int singleNonDuplicateBS(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = (low + high) >> 1;
            int num = (mid%2==0) ? mid+1 : mid-1; /*split with mid make last even half hence checking if mid 
            is odd then 1st half is odd and if mid even then 1st half even*/
            if(nums[mid] == nums[num]) low = mid+1; /*if arr idx at num=mid+1 has same value at mid that means that half even size array has 1 element equal to mid hence 2nd-half-even-len-1 left which is odd since all are paired then that one remaining if in right hence low=mid+1*/
            else high = mid;
        }
        return nums[low];
    }


public:
    int singleNonDuplicate(vector<int>& nums) {
        return singleNonDuplicateBS(nums);
    }
    
};
