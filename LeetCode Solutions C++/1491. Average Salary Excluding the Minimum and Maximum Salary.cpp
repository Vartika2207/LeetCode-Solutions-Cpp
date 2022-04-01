class Solution {
public:
  time: O(nlogn)
    double average(vector<int>& salary) {
        int n = salary.size();
        
        if(n <= 2)
            return 0;
        
        sort(salary.begin(), salary.end());
        double sum = accumulate(salary.begin() + 1, salary.end() - 1, 0); // add all elements excluding 1st and last
        
        return sum/(n-2);
        
    }
};
