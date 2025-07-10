class Solution {
public:
    int start = 0, maxLen = 1;

    bool isPalindrome(int i, int j, string &s, vector<vector<int>>& dp) {
        // base cases
        if (i >= j) return true;

        // memoized
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {
            // check inner substring
            if (isPalindrome(i + 1, j - 1, s, dp)) {
                // update longest palin substring if needed
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                }
                return dp[i][j] = true;
            }
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                isPalindrome(i, j, s, dp);
            }
        }

        return s.substr(start, maxLen);
    }
};
