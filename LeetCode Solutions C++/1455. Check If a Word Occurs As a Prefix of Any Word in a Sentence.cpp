class Solution {
public:
    //time: O(len(sentence)), space: O(1)
    int isPrefixOfWord(string sentence, string searchWord) {
        // Breaking input into word
        // using string stream
        stringstream s(sentence);
        string word;
        
        int idx = 1;
        while(s >> word){
            if(word.find(searchWord) < 1) //check if searchWord is present or not
                return idx;
            idx++;
        }
        return -1;
    }
};
