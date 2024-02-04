class Solution {
public:
//  time: O(s + t), O(n)
    string minWindow(string s, string t) {
        
        int l = 0, r = 0;
        unordered_map<char, int> windowFreq, tFreq;
        for(auto i: t)
            tFreq[i]++;
        int reqChar = tFreq.size();
        string minStr; int minStrLen = INT_MAX;
        int minStart = 0;
        while(r < s.size()) {
            char curChar = s[r];
            windowFreq[curChar]++;
            if(tFreq.count(curChar) != 0 and windowFreq[curChar] == tFreq[curChar])
                reqChar--;
            while(reqChar == 0) {
                // capturing string in the window
                if( r-l+1 < minStrLen) {
                    minStrLen = r - l + 1;
                    minStart = l;
                    // minStr = s.substr(l, minStrLen);
                } 
                // reducing window size
                char leftChar = s[l];
                windowFreq[leftChar]--;
                l++;
                if(tFreq.count(leftChar) != 0 and windowFreq[leftChar] < tFreq[leftChar])
                    reqChar++;
            }
            r++;
        }
        return minStrLen != INT_MAX ? s.substr(minStart, minStrLen) : "";
    }
};




///////////////////////////////////
class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size();  int t_len = t.size();
        if(s_len < t_len)
            s.swap(t);
        
        int left = 0, right = 0, subStr_freq = 0;
        string ans = "";
        unordered_map<char, int> s_mp, t_mp;
        
        //counting frequecy for t
        for(auto ch: t){
            t_mp[ch]++;
        }
        
        while(left <= right){
            
            //aquire the string
            if(t_len > subStr_freq){
                if(right > s_len)
                    break;
                s_mp[s[right]]++;
                if(t_mp.find(s[right]) != t_mp.end() and t_mp[s[right]] >= s_mp[s[right]])
                    subStr_freq++;
                right++;
            }
            //release
            else{
                s_mp[s[left]]--;
                if(t_mp.find(s[left]) != t_mp.end() and t_mp[s[right]] > s_mp[s[right]])
                    subStr_freq--;
                left++;
            }
            if(subStr_freq == t_len){
                string temp = s.substr(left, right - left + 1);
                if(ans.size() == 0 or temp.size() < ans.size())
                    ans = temp;
            }
        }
        return ans;
    }
};
