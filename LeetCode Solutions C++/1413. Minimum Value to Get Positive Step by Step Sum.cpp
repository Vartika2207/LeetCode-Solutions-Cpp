class Solution {
    //time: 0(n^2 * m)  n be the length of the array, m be the absolute value of the lower bound of elements in nums
    int minStartValue_1(vector<int>& nums) {
        
        int startVal = 1;
        bool isValid = true;
        
        while(true){
            int total = startVal;
            bool isValid = true;
            
            for(int i : nums){
                total += i;
                
                if(total < 1){
                    isValid = false;
                    break;
                }
            }
            if(!isValid)
                startVal += 1;
            else 
                return startVal;
        }
        
        return -1;
    }
    
    //time: 0(n), space: O(1)
    int minStartValue_3(vector<int>& nums){
        int total = 0, minVal = 0;
        for(int i: nums){
            total += i;
            minVal = min(minVal, total);
        }
        return (minVal*-1) + 1;
    }
    
public:
    int minStartValue(vector<int>& nums) {
        return minStartValue_3(nums);
    }
};
