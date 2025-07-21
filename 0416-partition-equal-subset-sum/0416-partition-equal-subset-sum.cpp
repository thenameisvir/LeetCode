class Solution {
public:
    bool solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i >= nums.size() || target < 0) return false;

        if (dp[i][target] != -1) return dp[i][target];

        bool inc = solve(nums, target - nums[i], i + 1, dp);
        bool exc = solve(nums, target, i + 1, dp);

        return dp[i][target] = inc || exc;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(nums, target, 0, dp);
    }
};
