class Solution {
public:
//time: O(n^2), space: O(n)
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string lexo_string = s;
            for(int i=0; i<s.size(); i++){
                string temp = s.substr(i) + s.substr(0, i);
                lexo_string = min(lexo_string, temp);
            }
            return lexo_string;
        }
        else{
            sort(s.begin(), s.end());
            return s;
        }
    }
};
