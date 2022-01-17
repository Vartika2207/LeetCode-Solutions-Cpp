class Solution {
public:
    //time: O(n), space: O(n)
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        int word_count=0;
        istringstream ss(s);
        while(ss >> word){
            v.push_back(word);
            word_count++;
        }
        
        //if pattern.length not equal to word count in s
        if(word_count != pattern.size())
            return 0;
        
        set<string> used_word; //to store words in s
        map<char, string> mp; //to store pattern alphabet corresponding to word in s
        
        for(int i=0; i<pattern.size(); i++){
            if(!mp.count(pattern[i]) && !used_word.count(v[i])){
                mp[pattern[i]] = v[i];
                used_word.insert(v[i]);
            }
            else if(mp[pattern[i]] == v[i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
