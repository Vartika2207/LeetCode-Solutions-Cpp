class Solution {
    int threeSum(vector<int>& nums, int target){
        
        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size()-2;i++){
                int s=i+1;
                int e=nums.size()-1;
                
                while(s<e){
                    int sum = nums[i] + nums[e] + nums[s];
                    
                    if(abs(-target + sum ) < abs(-target + closest))  {
                        closest = sum;
                    } 
                    
                    if(target==sum){
                        break;
                    }
                     
                    else if(target < sum) e--;
                    else s++;
            }
          }
        return closest;
    }
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return threeSum(nums, target);
    }
};
