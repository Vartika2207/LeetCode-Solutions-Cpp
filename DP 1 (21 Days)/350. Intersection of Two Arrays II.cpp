class Solution {
public:
    //METHOD-1
    //time: O(n), space: O(n)
    vector<int> intersect_helper(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i]]++;
        }
        
        vector<int> answer;
        for(int i=0; i<nums2.size(); i++){
            if(mp[nums2[i]] > 0){
                answer.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return answer;
    }
    
    /****************************/
    
    //METHOD-2
    //time: O(n), space: O(1)
    vector<int> intersect_(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());
        return nums1;
    }
    /****************************/
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        return intersect_(nums1, nums2);
    }
};
