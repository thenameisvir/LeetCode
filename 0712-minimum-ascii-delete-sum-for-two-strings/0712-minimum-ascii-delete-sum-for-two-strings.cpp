class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: delete remaining characters when one string is empty
        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = int(s1[i]) + dp[i + 1][m];
        }

        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = int(s2[j]) + dp[n][j + 1];
        }

        // Fill dp table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int op1 = int(s1[i]) + dp[i + 1][j];   // delete from s1
                    int op2 = int(s2[j]) + dp[i][j + 1];   // delete from s2
                    dp[i][j] = min(op1, op2);
                }
            }
        }

        return dp[0][0];
    }
};
