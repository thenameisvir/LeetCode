
class Solution {
public:
    int solve(vector<int>& nums, int index, int remainder, vector<vector<int>>& dp) {
        // Base case
        if (index >= nums.size()) return (remainder == 0) ? 0 : INT_MIN;

        // Memoization check
        if (dp[index][remainder] != -1) return dp[index][remainder];

        // Include current number
        int inc = nums[index] + solve(nums, index + 1, (remainder + nums[index]) % 3, dp);

        // Exclude current number
        int exc = solve(nums, index + 1, remainder, dp);

        // Store max sum that is divisible by 3
        return dp[index][remainder] = max(inc, exc);
    }

    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1)); // DP for index + remainder states
        return max(0, solve(nums, 0, 0, dp));  // Ensure non-negative answer
    }
};