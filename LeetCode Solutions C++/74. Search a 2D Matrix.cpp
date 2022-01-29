class Solution {
public:
    
    //method1: do linear search , time O(n*n), space O(1)
    
    //method2: do bianry search on row
    //time O(nlogm), space : O(1)
    bool searchMatrix_app1(vector<vector<int>>& mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        int i=0, j=m-1;
        while(i<n && j>=0){
            if(mat[i][j] == x)
                return true;
            if(mat[i][j] < x)
                i++;
            else 
                j--;
        }
        return false;
    }
    
    //method3: do bianry search
    //time O(log(n*m)), space : O(1)
    bool searchMatrix_better(vector<vector<int>>& mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0, high=m*n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(mat[mid/m][mid%m] == x)
                return true;
            if(mat[mid/m][mid%m] < x)
                low=mid+1;
            else 
                high=mid;
        }
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& mat, int x){
        return searchMatrix_app1(mat,x);
    }
    
};
