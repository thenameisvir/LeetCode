class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i, vector<vector<int>>& dp) {
        if (sum == 0) return 0;             // No coins needed to make 0
        if (i >= coins.size() || sum < 0) return 1e9;  // Invalid path

        if (dp[sum][i] != -1) return dp[sum][i];

        // include current coin
        int inc = 1 + solve(coins, sum - coins[i], i, dp); 

        // exclude current coin
        int exc = solve(coins, sum, i + 1, dp);        

        return dp[sum][i] = min(inc, exc);
    }

    int coinChange(vector<int>& coins, int sum) {
        vector<vector<int>> dp(sum + 1, vector<int>(coins.size() + 1, -1));
        int ans = solve(coins, sum, 0, dp);
        return (ans >= 1e9) ? -1 : ans;  // If not possible to form sum
    }
};
