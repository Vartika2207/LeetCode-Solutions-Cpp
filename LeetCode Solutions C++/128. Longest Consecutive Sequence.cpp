class Solution {
    // time: O(nlogn + n); space: O(n)
    int longestConsecutive_map(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i: nums) {
            mp[i]++;
        }

        int lcs = 0;
        for(int i=0; i<nums.size(); i++) {
            int count = 0;
            int ele = nums[i];
            // check if nums[i] has been checked as a part of series
            if(mp[ele] == -1)
               continue;

            // series greater than nums[i]
            while(mp[ele]) {
                mp[ele] = -1;
                count++;
                ele++;
            }

            // series lesser than nums[i]
            ele = nums[i]-1;
            while(mp[ele]) {
                mp[ele] = -1;
                count++;
                ele--;
            }

            lcs = max(lcs, count);
        }
        return lcs;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        return longestConsecutive_map(nums);
    }
}; 
