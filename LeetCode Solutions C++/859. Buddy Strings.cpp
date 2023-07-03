class Solution {
public:
 /*  APPROACH-1  */
    bool buddyStrings_set(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n != m)
            return false;
        
        if (s == goal && unordered_set<char>(s.begin(), s.end()).size() < n) // if .size()==s.size()=> no swap possible
            return true;
        
        vector<int> difference;
        for (int i = 0; i < n; i++) 
            if (s[i] != goal[i]) difference.push_back(i);
        
        return difference.size() == 2 && s[difference[0]] == goal[difference[1]] && s[difference[1]] == goal[difference[0]];
    }

    /*  APPROACH-2  */
    bool buddyStrings_twoPoint(string s, string goal) {
        int n = s.length();
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }

        int i = 0, j = n - 1;

        while(i < j && s[i] == goal[i]) // i is where 1st miss-match occurred
            i++;
        
        while(j >= 0 && s[j] == goal[j]) // j is where 2st miss-match occurred
            j--;
        

        if(i < j)
            swap(s[i], s[j]);
        
        return s == goal;
    }
    
    bool buddyStrings(string s, string goal) {
        return buddyStrings_twoPoint(s, goal);
    }
};
