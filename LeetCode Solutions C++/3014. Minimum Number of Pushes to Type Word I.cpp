class Solution {
public:
//     my approach
    int minimumPushes_naive(string word) {
        int push_count=0;
        int push=1;
        int n=word.size();
        if(n <= 8)
            return n;
        while(n > 8) {
            push_count += (8)*push;
            push++; 
            // if(n-8 <= 8)
            //     return push_count+n*push;
            n -= 8;
        }
        return push_count+n*push;
    }
    
    //approach1: time: O(nlogn), space: O(n)
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> frq(26, 0);
        for(auto i: word)
            frq[i-'a']++;
        sort(begin(frq), frq.end(), greater<int>());
        
        int count = 0;
        for(int i=0; i<n; i++) {
            int push = i/8+1;
            count += frq[i]*push;
        }
        return count;
    }
};
