class Solution {
public:
  //time:O(nlogn), space: O(n)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1)
            return false;
        map<int, int> mp;
        
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = i;
            else{
                if(abs(mp[nums[i]] - i) <= k)
                    return true;
                else 
                    mp[nums[i]] = i;
            }
        }
        
        return false;
    }
};
