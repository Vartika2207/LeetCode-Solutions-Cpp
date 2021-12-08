class Solution {
    /********************************/
    //time: O(n^2), space: O(1)
    int numIdenticalPairsBrute(vector<int> &nums){
        const int n = nums.size();
        int pair = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j])
                    pair++;
            }
        }
        return pair;
    }
    /********************************/
    
    /********************************/
    //time: O(n), space: O(n)
    int numIdenticalPairsBetter(vector<int> &nums){
        const int n = nums.size();
        int pair = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            pair += mp[nums[i]]++;
        }
        return pair;
    }
    /********************************/
    
public:
    int numIdenticalPairs(vector<int>& nums) {
        return numIdenticalPairsBetter(nums);
    }
};
