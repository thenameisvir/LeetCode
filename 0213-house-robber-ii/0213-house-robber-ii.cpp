class Solution {
public:
    int solve(vector<int>& nums, int i, int size, vector<int>& dp) {
        if (i > size) {
            return 0;
        }

        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        int inc = nums[i] + solve(nums, i + 2, size, dp);
        int exc = solve(nums, i + 1, size, dp);

        return dp[i] = max(inc, exc);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> dp1(nums.size(), INT_MIN);
        vector<int> dp2(nums.size(), INT_MIN);

        int ans = solve(nums, 0, nums.size() - 2, dp1);
        int ans2 = solve(nums, 1, nums.size() - 1, dp2);

        return max(ans, ans2);
    }
};
