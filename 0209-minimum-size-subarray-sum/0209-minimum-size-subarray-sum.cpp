class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int sum = 0, left = 0, ans = INT_MAX;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            // Shrink the window from the left as long as the sum is greater than or equal to the target
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= arr[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans; // If no valid subarray is found, return 0
    }
};
