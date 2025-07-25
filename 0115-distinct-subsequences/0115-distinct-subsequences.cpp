class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(j == t.size()) return 1; // t fully matched
        if(i == s.size()) return 0; // s exhausted

        if(dp[i][j] != -1) return dp[i][j];

        int include = 0;
        if(s[i] == t[j]) {
            include = solve(s, t, i + 1, j + 1, dp); // match and move both
        }

        int exclude = solve(s, t, i + 1, j, dp); // skip s[i]

        return dp[i][j] = include + exclude;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};
