class Solution {
// approach 1: perfect square property i.e. perfect sqr of x is sum of first x consecutive odd num => tc: O(sqrt(x))
// https://en.wikipedia.org/wiki/Square_number#/media/File:The_sum_of_the_first_n_odd_integers_is_n%C2%B2._1+3+5+...+(2n-1)=n%C2%B2..gif
    int mySqrtPerfectSqr(int x) {
        int i = 1;
        while (x > 0) {
            x -= i;
            i += 2;
        }
        return (x == 0);
    }

// approach1: binary search => time: O(logx)
    int mySqrtBS(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x;
        while (first <= last) {
            long long int mid = first + (last - first) / 2;
            // mid * mid == x gives runtime error
            if (mid*mid  == x)
                return 1;
            else if (mid > x/mid) 
                last = mid - 1;
            else 
                first = mid + 1;
        }
        return 0;
    }

// approach2: newton's method =>tc O(logx), 
    int mySqrtNewton(int x) {
        long long int sqrt = x;
        while(sqrt * sqrt > x) {
            sqrt = (sqrt + x/sqrt)/2;
        }
        return (sqrt*sqrt == x);
    }

public:
    bool isPerfectSquare(int num) {
        return mySqrtPerfectSqr(num);
    }
};
