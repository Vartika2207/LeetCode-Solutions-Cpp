class Solution {
    int minOperationsNaive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int count = 0;
        for(auto i: nums)
            mp[i]++;
        for(auto itr: mp) {
            if(itr.second == 1)
                return -1;
            count += ceil(double(itr.second)/3);
        }
        return count;
    }

public:
    int minOperations(vector<int>& nums) {
        return minOperationsNaive(nums);
    }
};
