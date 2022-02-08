class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer;
        map<int, int> mp;
        
        for(auto i: nums)
            mp[i] ++;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == 1)
                answer.push_back(it->first);
        }
        return answer;
    }
};
