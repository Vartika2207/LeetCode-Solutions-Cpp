class Solution {
public:
//time: O(n)
    int maxProfit(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]) sum+=arr[i]-arr[i-1];
        }
        return sum;
    }
};
