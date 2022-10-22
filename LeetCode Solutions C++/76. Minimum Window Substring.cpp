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
