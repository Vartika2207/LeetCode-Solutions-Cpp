class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3)
            return false;
        
        bool inc = true;
        for(int i=1; i<arr.size(); i++){
            if(i == 1 && (arr[i-1] > arr[i]))
                return false;
            
            if(arr[i-1] == arr[i])
                return false;
            
            if(inc == true && arr[i-1] > arr[i])
                inc = false;
            
            if(inc == false && (arr[i-1] < arr[i]))
                return false;
        }
        return (inc == true ? false : true);
    }
};
