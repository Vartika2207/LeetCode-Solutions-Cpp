class Solution {
// approach 1: liner search in O(n)

// approach 2: binary search in O(logn)
    int peakIndexInMountainArrayBS(vector<int>& arr) {
        int n = arr.size();
        int first = 0, last = n-1;
        while(first <= last) {
            int mid = (first + last)/2;
            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] > arr[mid+1])
                last = mid; // 
            else 
                first = mid+1;
        }
        return 0;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return peakIndexInMountainArrayBS(arr);
    }
};
