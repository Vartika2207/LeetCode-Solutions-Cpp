class Solution {
    // app1: time: O(n.logn), space: O(n)
    vector<vector<int>> findWinners_naive(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int, pair<int, int>> mp; //scoreBoard
        for(int i=0; i<n; i++) {
            int win = matches[i][0], lost = matches[i][1];
            if(mp.find(win) == mp.end()) {
                mp[win].first = 0; mp[win].second = 0;
            }
            if(mp.find(lost) == mp.end()) {
                mp[lost].first = 0; mp[lost].second = 0;
            }
            mp[win].first++; //win score increased
            mp[lost].second++;
        }
        for(auto m: mp) {
            cout << m.first << " " << m.second.first << " " << m.second.second <<  endl;
        }
        vector<vector<int>> answer(2);
        for(auto m: mp) {
            if(m.second.second == 0)
                answer[0].push_back(m.first);
            if(m.second.second == 1)
                answer[1].push_back(m.first);
        }
        return answer;
    }
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        return findWinners_naive(matches);
        // return findWinners_better(matches);
    }
};
