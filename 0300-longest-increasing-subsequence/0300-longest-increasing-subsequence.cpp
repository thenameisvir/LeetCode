class Solution {
public:
    int solve(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {
        if (i >= nums.size()) return 0;

        if (dp[i][prev + 1] != INT_MIN) return dp[i][prev + 1];

        int inc = 0, exc = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            inc = 1 + solve(nums, i + 1, i, dp);
        }
        exc = solve(nums, i + 1, prev, dp);

        dp[i][prev + 1] = max(inc, exc);
        return dp[i][prev + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // prev ranges from -1 to n-1, so we need n+1 size in second dimension
        vector<vector<int>> dp(n+1, vector<int>(n + 1, INT_MIN));
        return solve(nums, 0, -1, dp);
    }
};
