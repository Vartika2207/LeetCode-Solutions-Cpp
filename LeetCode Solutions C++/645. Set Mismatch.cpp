class Solution {
private:
// app1: use map to store freq and check who have frq[ele]==0 and frq[ele]==2
// time: O(N), space: O(n) map used
    vector<int> findErrorNums_app1(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=1; i<=n; i++)
            mp[i] = 0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] == 2)
                ans.push_back(nums[i]);
        }

        for(int i=1; i<=n; i++) {
            if(mp[i] == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }

    // approach2: check in array in single traverse which element is missing and which is duplicate
    // time: O(nlogn), space: O(1)
    vector<int> findErrorNums_app2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2, -1);
        int n = nums.size();
        // finds missing number
        for(int i=1; i<=n; i++) {
            if(ans[1] == -1 and nums[i-1] != i) {
                ans[1] = i;
            }
            if(i < n and nums[i-1] == nums[i]) {
                ans[0] = nums[i];
            }
        }
        return ans;
    }

    // time: O(N), space: O(n)  
    vector<int> findErrorNums_app3(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2,0);
        int sumOfArray = accumulate(begin(nums), end(nums), 0);
        int sumOfN = (n+1)*n/2;
        int sumOfUnique = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int a : s) {
            sumOfUnique += a;
        }
        return {sumOfArray-sumOfUnique, sumOfN-sumOfUnique};
    }
public:
    vector<int> findErrorNums(vector<int>& nums) {
        return findErrorNums_app3(nums);
    }
};
