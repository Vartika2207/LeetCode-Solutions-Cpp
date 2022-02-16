class Solution {
public:
    //time: 0(logn), space: O(1)
    int search(vector<int>& nums, int target) {
        int s=0, e=nums.size() - 1;
        
        while(e >= s){
            int mid= (s+e)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return -1;
    }
};
