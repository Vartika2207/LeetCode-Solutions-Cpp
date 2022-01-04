class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(!n)
            return 1;
        
        int ans = 0;
        int i  = 0;
        while(n){
            int bit = n & 1;
            ans += (1 ^ bit) * (pow(2,i));
            i++;
            n >>= 1;
        }
        return ans;
    }
};
