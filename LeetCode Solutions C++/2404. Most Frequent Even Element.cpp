class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        
        int maxFreqNum = INT_MAX, maxFreq = 0;
        for(auto i: nums){
            if(i & 1) continue; //i is odd
            
            mp[i]++;
            if(mp[i] >= maxFreq){
                maxFreqNum = mp[i] == maxFreq ? min(i, maxFreqNum) : i;
                maxFreq = mp[i];
            }
        }
        return (maxFreqNum == INT_MAX) ? -1 : maxFreqNum;
    }
};
