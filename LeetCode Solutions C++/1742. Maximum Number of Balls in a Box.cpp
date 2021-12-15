class Solution {
     int sumOfDigits(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int countBalls(int l, int h) {
        map<int,int>mp;
        int maxBalls = 0;
        for(int i=l; i<=h; i++){
            int boxNum = sumOfDigits(i);
            mp[boxNum]++;
            maxBalls = max(maxBalls, mp[boxNum]);
        }
        return maxBalls;
    }
};
