class Solution {
public:
  //time: O(n), space: O(n)
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        
        map<char, int> mp1;
        for(int i=0; i<s.size(); i++){
            mp1[s[i]]++;
            mp1[t[i]]--;
        }
    
        for(int i=0; i<t.size(); i++){
            if(mp1[s[i]])
                return false;
        }
        return true;
    }
};
