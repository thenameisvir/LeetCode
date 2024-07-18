class Solution {
public:
    // Function to find the index of the pivot element
    int pivot(const vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int n = arr.size();
        
        while (s < e) {
            int m = s + (e - s) / 2;
            if (arr[m] > arr[e]) {
                s = m + 1;
            } else {
                e = m;
            }
        }
        return s; // 's' is the index of the smallest element, i.e., the pivot
    }

    // Function to perform binary search on the subarray
    int binarysearch(const vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (arr[m] == target) {
                return m;
            } else if (arr[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1; // Element not found
    }

    // Main function to search for the target in the rotated sorted array
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 0) return -1; // Empty array
        
        int pivotIndex = pivot(arr);

        // If the array is not rotated
        if (pivotIndex == 0) {
            return binarysearch(arr, 0, n - 1, target);
        }
        
        // If target is within the left part of the array
        if (target >= arr[0] && target <= arr[pivotIndex - 1]) {
            return binarysearch(arr, 0, pivotIndex - 1, target);
        }

        // If target is within the right part of the array
        return binarysearch(arr, pivotIndex, n - 1, target);
    }
};
