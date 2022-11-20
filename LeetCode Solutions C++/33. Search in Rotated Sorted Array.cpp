class Solution {
    //time: O(logn), space: O(1)
    int searchBinary(vector<int>& nums, int t){
        int n = nums.size();
        int start = 0, end = n-1;
        
        while(start <= end){
            int mid = (start + end)/2;
            
            if(nums[mid] == t)
                return mid;
            
            //left sorted arr found
            if(nums[mid] >= nums[start]){ 
                //check if target can be in between range at left
                if(t <= nums[mid] and t >= nums[start])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else{
                //no sorted arr found
                if(t <= nums[end] and t >= nums[mid])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        return searchBinary(nums, target);
    }
};
