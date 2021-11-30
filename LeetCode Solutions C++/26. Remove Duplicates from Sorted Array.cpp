class Solution {
public:
    /**************/
    //time: O(n*logn) + O(n)
    int removeDuplicatesBrute(vector<int>& nums) {
        set<int> m;
        for(int i=0; i<nums.size(); i++){
            m.insert(nums[i]);//O(lg n) to insert
        }
        nums.clear();
        static int i = 0;
        for(auto X: m){
            nums .push_back(X);
        }
        return m.size();
    }
    /*******************/
    
    /*****************/
    //time: O(n), space: 0(1)
    int removeDuplicatesBetter(vector<int>& nums) {
        if(!nums.size())
            return 0;
        
        int i=0, j=1;
        while(j < nums.size()){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
     }
    /*****************/
    
    
    
     int removeDuplicates(vector<int>& nums) {
         return removeDuplicatesBetter(nums);
     }
};