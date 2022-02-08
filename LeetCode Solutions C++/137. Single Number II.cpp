class Solution {
public:
    //time: O(n), space: O(n)
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == 1)
                return it->first;
        }
        return -1;
    }
};
