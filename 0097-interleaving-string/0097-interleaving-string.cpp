class Solution {
public:
    int dp[105][105]; // assuming s1 and s2 length <= 100

    bool solve(string& s1, string& s2, string& s3, int i, int j) {
        int k = i + j;
        
        // Base case: if all strings are consumed
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        // If next char in s1 matches s3
        if (i < s1.size() && s1[i] == s3[k]) {
            ans |= solve(s1, s2, s3, i + 1, j);
        }

        // If next char in s2 matches s3
        if (j < s2.size() && s2[j] == s3[k]) {
            ans |= solve(s1, s2, s3, i, j + 1);
        }

        // Store and return result
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        // Edge case: if lengths don't match
        if (s1.size() + s2.size() != s3.size()) return false;

        memset(dp, -1, sizeof(dp)); // initialize DP array
        return solve(s1, s2, s3, 0, 0);
    }
};
