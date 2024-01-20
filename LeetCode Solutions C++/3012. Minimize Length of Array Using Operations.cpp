class Solution {
    private:
    int minimumArrayLength_naive(vector<int>& nums) {
        int v = *min_element(nums.begin(), nums.end());
        //size depends on smallest ele bcz [1,3,4] => [3%1,4]=>[4%3]=> [1]
        
        for (int x : nums) 
            // if we found x%v == 0 which means that we have more than one min and that will an (count(v)+1)/2 case
            // [1,1,1,1,1]5=>[0,0,1]3 | [1,1,1,1,1,1]6=>[0,0,0]3 | [1,1,1,1]4=>[0,0]2 | [1,1,1]3=>[0,0]2=> (count(n)+1)/2 
            if (x % v != 0) {
                return 1;
        }
        
        int x = count(nums.begin(), nums.end(), v);  //counting feq of min ele
        return (x + 1) / 2;
    }
    
public:
    int minimumArrayLength(vector<int>& nums) {
        return minimumArrayLength_naive(nums);
    }
};
