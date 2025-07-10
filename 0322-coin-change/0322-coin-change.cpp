class Solution {
public:
    int tab(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; 

        for (int value = 1; value <= amount; value++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (coins[i] > value) continue; 

                int recAns = dp[value - coins[i]];
                if (recAns != INT_MAX) { 
                    mini = min(mini, 1 + recAns);
                }
            }
            dp[value] = mini;
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount]; 
    }

    int coinChange(vector<int>& coins, int amount) {
        return tab(coins, amount);
    }
};
