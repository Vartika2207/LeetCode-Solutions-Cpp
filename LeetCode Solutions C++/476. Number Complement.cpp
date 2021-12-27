class Solution {
public:
    int findComplement(int num) {
        
        int *arr = new int[32]();
        int size = 0;
        while(num){
            arr[size] = num % 2;
            num /= 2;
            size++;
        }
        
        int complement = 0;
        for(int i=0; i<size; i++){
            arr[i] = arr[i] xor 1; //or 1 - arr[i]
            complement = complement + arr[i] * pow(2, i);
        }
        return complement;
        
        
    }
};
