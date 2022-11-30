class Solution {
    //time: O(n), space: O(n)
    bool uniqueOccurrences_bruteForce(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto i: arr){
            mp[i]++;
        }
        
        unordered_set<int> st;
        for (auto i = mp.begin(); i != mp.end(); i++){
              st.insert(i->second);
        }
        return st.size() == mp.size();
    }
    
    public:
    bool uniqueOccurrences(vector<int>& arr){
        return uniqueOccurrences_bruteForce(arr);
    }
};
