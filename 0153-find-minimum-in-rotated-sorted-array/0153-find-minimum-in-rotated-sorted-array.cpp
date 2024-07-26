class Solution {
public:
    int binary(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        
        // Handle the single element case
        if (arr.size() == 1) {
            return arr[0];
        }

        // If the array is not rotated
        if (arr[s] < arr[e]) {
            return arr[s];
        }

        while (s <= e) {
            int m = s + (e - s) / 2;
            
            // Check for the pivot point
            if (m > 0 && arr[m] < arr[m - 1]) {
                return arr[m];
            }
            if (m < arr.size() - 1 && arr[m] > arr[m + 1]) {
                return arr[m + 1];
            }

            // Adjust search range
            if (arr[m] >= arr[s]) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return -1; // This line should not be reached
    }
    
    int findMin(vector<int>& arr) {
        return binary(arr);
    }
};
