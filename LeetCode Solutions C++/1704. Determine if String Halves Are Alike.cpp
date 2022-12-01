class Solution {
//time: O(len(n)), space: O(1)
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    
    int countVowel(string str){
        int count = 0;
        for(auto s: str){
            if(isVowel(s))
                count++;
        }
        return count;
    }
    
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        
        string a = s.substr(0, n/2); cout<<a<<endl;
        string b = s.substr(n/2, n/2);cout<<b<<endl;
        
        return countVowel(a) == countVowel(b);
    }
};
