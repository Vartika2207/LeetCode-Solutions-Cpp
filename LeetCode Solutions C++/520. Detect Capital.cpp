class Solution {
    
    bool isUpper_case(char a){
        if(a >= 65 && a <= 90)
            return true;
        return false;
    }
    
     bool isLower_case(char a){
        if(a >= 97 && a <= 122)
            return true;
        return false;
    }
    
public:
    bool detectCapitalUse(string word) {
        int lower_case_alpha = 0; //to keep cout of all lower case alphabets
        int upper_case_alpha = 0; //to keep cout of all upper case alphabets
        
        for(int i=0; i<word.size(); i++){
            if(isUpper_case(word[i]))
                upper_case_alpha++;
            
            else if(isLower_case(word[i]))
                lower_case_alpha++; 
            
        }
        
        //case 1:if all alphabets are either lower case or upper case 
        if(upper_case_alpha == word.size() || lower_case_alpha == word.size())
            return true;
        //case 2: if only 1st aphabet is upper case
        if((isUpper_case(word[0]) && upper_case_alpha == 1) && lower_case_alpha == word.size()-1)
            return true;
        return false;
        
        //case 1 Example: "IBM", "leetcode"
        //case 2 Example: "Google"
    }
};
