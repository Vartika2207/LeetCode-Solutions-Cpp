class Solution {
public:
// approach1: time: O(nlogn), O(n)
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> frq(26, 0);
        for(auto i: word)
            frq[i-'a']++;
        sort(frq.begin(), frq.end(), greater<int>());
        
        int count = 0;
        for(int i=0; i<26; i++) {
            int push = i/8+1;
            count += frq[i]*push;
        }
        return count;
    }
};
