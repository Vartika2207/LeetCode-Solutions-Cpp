class Solution {
    int mySqrtBS(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            // mid * mid == x gives runtime error
            if (mid  == x / mid)
                return mid;
            else if (mid > x / mid) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        return last;
    }

// approach 2: newtons's method => https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division

    int mySqrtNewton(int x) {
        long sqrt = x;
        while(sqrt*sqrt > x) 
            sqrt = (sqrt + x/sqrt)/2;
        return sqrt;
    }

public:
    int mySqrt(int x) {
        return mySqrtNewton(x);
    }
};
