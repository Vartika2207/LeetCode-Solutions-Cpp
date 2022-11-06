class Solution {
public:
    //time: O(nlogn),
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        
        for(auto i: arr){
            if(ans.empty() or i[0]>ans.back()[1])
                ans.push_back(i);
            else
                ans.back()[1] = max(i[1], ans.back()[1]);
        }
        return ans;
    }
};
