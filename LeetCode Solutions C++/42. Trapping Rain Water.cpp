class Solution {
public:
    //time: O(3N), space: O(2N)
    int perfix_surfix_method(vector<int> &h){
        int n = h.size();
        
        if(n == 0)
            return 0;
        
        int *pre = new int[n]();
        int *sur = new int[n]();
        
        
        pre[0] = h[0];
        for(int i=1; i<n; i++){
            pre[i] = max(h[i], pre[i-1]);
        }
        
        sur[n-1] = h[n-1];
        for(int i=n-2; i>=0; i--){
            sur[i] = max(h[i], sur[i+1]);
        }
        
        int water = 0;
        for(int i=0; i<n; i++){
            water += min(pre[i], sur[i]) - h[i];
        }
        
        //free space
        delete[] pre, sur;
        return water;
    }
    
    
    int trap(vector<int>& h) {
        return perfix_surfix_method(h);
    }
};
