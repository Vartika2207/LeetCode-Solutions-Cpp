class Solution {
    //Approach 2: One Pointer
    //Approach 1: Two Pointers
    
    //Approach 3: Recursion
    string mergeAlternatelyRec(string w1, string w2) {
        if(!w1.size() or !w2.size())
            return !w1.size()?w2:w1;
        
        string answer;
        answer.push_back(w1[0]);
        answer.push_back(w2[0]);
        
        string smallAns = mergeAlternatelyRec(w1.substr(1), w2.substr(1));
        return answer+smallAns;
    }
        
        
        
public:
    string mergeAlternately(string w1, string w2) {
        return mergeAlternatelyRec(w1, w2);
    }
};
