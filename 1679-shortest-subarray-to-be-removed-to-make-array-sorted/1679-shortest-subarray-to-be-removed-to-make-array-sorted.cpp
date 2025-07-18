class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        
        // Step 1: Find sorted prefix
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        if (left == n - 1) return 0; // Already sorted
        
        int right = n - 1;
        // Step 2: Find sorted suffix
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        int result = min(n - left - 1, right); // remove left or right

        // Step 3: Try to combine prefix & suffix using stack-like matching
        int i = 0;
        int j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};
