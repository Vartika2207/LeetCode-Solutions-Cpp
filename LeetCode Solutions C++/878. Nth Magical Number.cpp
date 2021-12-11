class Solution {
    const long mod = 1e9+7;
    
    /*********approach-1 => TLE************/
    //time: O(n)
    int nthMagicalNumber_brute(int n, int a, int b){
        int count = 0;
        long long int i = 0;
        for(i = 1;i < 1000000000; i++){
            if(i % a == 0 || i % b == 0)
                count = (count %mod + 1) % mod;
            if(count == n)
                return (int)i;
        }
        return i;
    }
   /*************************/ 
    
     /*********approach-2 => Passed************/
  //time: O(a+b)
    int nthMagicalNumber_better(int n, int a, int b){
        int l = a / __gcd(a, b) * b; //lcm, least common multiple
        int m = l/a + l/b - 1; //magical nums less than L, -1 since L repeats in both
        
        //n = m*q+r
        int q = n/m;
        int r = n%m;
        //The first L*q numbers(1 ...L*q) contain M∗q magical numbers, and within the next numbers (L*q + 1, L*q + 2, ...) we want to find r more magical ones.
        long answer = long((long)q * l % mod) % mod; //answer is the M*q th magical number from 1 to L*q
        if(r == 0)
            return (int)answer;
        
        int nextMagical[2] = {a, b};
        for(int i = 0;i < r-1; i++){
            if(nextMagical[0] <= nextMagical[1])
                nextMagical[0] += a;
            else
                nextMagical[1] += b;
        }
        answer += min(nextMagical[0], nextMagical[1]);
        return (int)(answer % mod);
    }
   /*************************/  
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        return nthMagicalNumber_better(n, a, b);
    }
};
