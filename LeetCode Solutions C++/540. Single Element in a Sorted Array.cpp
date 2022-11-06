class Solution {
public:
    //time: O(n), space: O(1)
    int singleNonDuplicate_xor(vector<int>& arr) {
        int num=arr[0];
        for(int i=1; i<arr.size(); i++){
            num ^= arr[i];
        }
        return num;
    }
    
    int singleNonDuplicate(vector<int>& arr) {
        return singleNonDuplicate_xor(arr);
    }
};
