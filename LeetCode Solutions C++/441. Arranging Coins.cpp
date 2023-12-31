class Solution {
// approach 1: linear search
    int arrangeCoinsLS(int n) {
        int i = 1;
        while(i <= n) {
            n = n - i;
            i++;
        }
        return i-1;
    }

// approach 2: binary search
    int arrangeCoinsBS(int n) {
        int l = 0, r = n-1;
        while(l <= r) {
            long long mid = (l + r)/2;
            if(n >= (mid*(mid+1)/2))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return (l-1);
    }

// appraoch 3: using formula constant space=> O(1)
/*1+2+3+...+x = n
-> (1+x)x/2 = n
-> x^2+x = 2n
-> x^2+x+1/4 = 2n +1/4
-> (x+1/2)^2 = 2n +1/4
-> (x+0.5) = sqrt(2n+0.25)
-> x = -0.5 + sqrt(2n+0.25)*/
    int arrangeCoinsFormula(int n) {
        return floor(sqrt((double)2*n + 0.25) + (-0.5)); //float is inbuilt function that returns an integer value that is less than or equal to the argument. 
    }

public:
    int arrangeCoins(int n) {
        return arrangeCoinsFormula(n);
    }
};
