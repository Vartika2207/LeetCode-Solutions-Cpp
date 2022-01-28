class Solution {
public:
    
    //tim e & space : O(n)
    vector<vector<int>> generate(int n) {
        vector<vector<int>>pascals(n);
        for(int i=0;i<n;i++){
            pascals[i].resize(i+1);
            pascals[i][0] = pascals[i][i] = 1;
            for(int j=1;j<i;j++){
                pascals[i][j]= pascals[i-1][j-1] + pascals[i-1][j];
            }
        }
        return pascals;
        
    }
};
