class Solution {
public:
    int solve(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        if (target == 0) return 0;  // Agar target pura ho gaya toh length return karo
        if (index >= nums.size() || target < 0) return INT_MIN;  // Out of bounds case
        
        if (dp[target][index] != -1) return dp[target][index];  // DP Check

        // Include current element
        int inc = 1 + solve(nums, target - nums[index], index + 1, dp);
        // Exclude current element
        int exc = solve(nums, target, index + 1, dp);

        dp[target][index] = max(inc, exc);
        return dp[target][index];
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(target + 1, vector<int>(n, -1));  // 2D DP
        
        int ans = solve(nums, target, 0, dp);
        return (ans < 0) ? -1 : ans;
    }
};
