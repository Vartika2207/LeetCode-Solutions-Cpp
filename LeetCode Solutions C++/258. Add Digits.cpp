class Solution {
public:
    int addDigits(int num) {
        if(num <= 9)
            return num;
        
        while(num > 9){
            int temp_sum = 0;
            int n = num;
            while(n){
                temp_sum += n%10;
                n /= 10;
            }
            num = temp_sum;
        }
        
        return num;
    }
};
