class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) 
            mp[nums[i]] = __builtin_popcount(nums[i]);
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] > nums[j]) {
                    if(mp[nums[i]] == mp[nums[j]])
                    swap(nums[i], nums[j]);
                    else return false;
                }
            }
        }
        return true;
    }
};
