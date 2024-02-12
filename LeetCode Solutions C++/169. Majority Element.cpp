
class Solution {
    //app0: do binary search to count freq num[i] from j=i,j<n and check where frq>n/2; ->(time: O(n^2), space: O(1))
   
    // app1: use map to store freq and find max freq -> (time: O(nlogn+n), space: O(n))

    // app2: sort, use sliding window to find max window length  -> (time: O(nlogn+n), space: O(1))
    int majorityElement_app2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int majEle;
        while(r < n) {
            if(nums[r] == nums[l]) 
                r++;
            else {
                int windowLen =  r - l;
                if(windowLen > maxLen) {
                    maxLen = windowLen;
                    majEle = nums[l];
                }
                l = r;
            }
        }
        int windowLen =  r - l;
        if(windowLen > maxLen) {
            maxLen = windowLen;
            majEle = nums[l];
        }
        return majEle;
    }

    // app3: since majority ele is greater than n/2 hence will surly be mid element -> (time: O(nlogn), space: O(1))
    int majorityElement_app3(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        return nums[n/2];
    }

    // app4:boyer moore -> (time: O(n), space: O(1)): https://www.youtube.com/watch?v=nP_ns3uSh80
    int majorityElement_app4(vector<int>& nums) {
        int n = nums.size();
        int count = 0, majEle;
        int i = 0;
        while(i < n) {
            if(count == 0)
                majEle = nums[i];
            if(nums[i] == majEle)
                count++;
            else 
                count--;
            i++;
        }
        return majEle;
    }


public:
    int majorityElement(vector<int>& nums) {
        return majorityElement_app4(nums);
    }
};

///////////////////////////*
class Solution {
public:
    
    //method 1: using a mash map or unordered_map => time O(nlgn), space O(n)
    
    //method 2, time O(n), space O(1)
   /*The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of elements using linear time and constant space*/ 
    int mooreVotingAlgo(vector<int>& nums) {
        int count = 0; 
        int element = 0;
        for(int i=0; i<nums.size(); i++){
            if(count==0)
                element = nums[i];
            if(element == nums[i])
                count+=1;
            else
                count-=1;
        }
        return element;
    }
    
    int majorityElement(vector<int>& nums) {
        return mooreVotingAlgo(nums);
    } 
};
*///////////////////////////////
