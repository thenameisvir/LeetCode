class Solution {
public:
    int tab(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n + 1, INT_MAX); // ✅ Fix: INT_MAX se initialize kiya
        dp[0] = 0; // ✅ Fix: Base case

        for (int value = 1; value <= amount; value++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (coins[i] > value) continue; // ✅ Fix: Agar coin bada hai toh skip kar

                int recAns = dp[value - coins[i]];
                if (recAns != INT_MAX) { // ✅ Fix: Agar valid answer hai toh hi update kar
                    mini = min(mini, 1 + recAns);
                }
            }
            dp[value] = mini;
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount]; // ✅ Fix: Agar answer nahi bana toh -1 return karna
    }

    int coinChange(vector<int>& coins, int amount) {
        return tab(coins, amount);
    }
};
