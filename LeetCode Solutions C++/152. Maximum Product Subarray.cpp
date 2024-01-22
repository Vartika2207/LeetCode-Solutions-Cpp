class Solution {
public:
// most optimized -- app1 | app3: sort and multiply, app2: run O(N*n) loop
// below is O(n)
    int maxProduct(vector<int>& nums) {
       int n = nums.size() ;
       int preProd = 1, sufProd = 1;
       int maxProdSub = INT_MIN;
       for(int i=0; i<n; i++) {
           if(preProd == 0) preProd = 1;
           if(sufProd == 0) sufProd = 1;
           preProd *= nums[i];
           sufProd *= nums[n-1-i];
           maxProdSub = max({maxProdSub, preProd, sufProd});
       }
       return maxProdSub;
    }
};
