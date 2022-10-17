class Solution {
//time: O(n), space: O(1)
public:
    bool checkIfPangram(string s) {
        int seen = 0;
        for(char curr: s){
            int asciiIndex = curr - 'a';
            int bit = 1 << asciiIndex;
            seen |= bit;
        }
        
        return (seen == ((1 << 26) - 1));
    }
};
