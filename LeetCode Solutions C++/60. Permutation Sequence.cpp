class Solution {
    //brute-force approach: time: O(n!*n)
    
    //optimal solution
    
public:
    //time: O(n*n), space: O(n)
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;
        for(int i=1; i<n; i++){
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        k -= 1; //we are taking 0-based indexing
        
        string ans = "";
        
        while(true){
            ans += to_string(num[k / fact]);
            num.erase(num.begin() + (k/fact));
            if(num.size() == 0)
                break;
            k = k % fact;
            fact /= num.size();
            
            }
    return ans;
    }
};
