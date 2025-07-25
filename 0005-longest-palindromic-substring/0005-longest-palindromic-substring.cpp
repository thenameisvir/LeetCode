class Solution {
public:
    int start = 0;
    int maxLen = 1;

    bool solve(int i, int j, string &s, vector<vector<int>> &dp) {
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s[i] == s[j]) {
            flag = solve(i+1, j-1, s, dp);
        }

        if(flag) {
            int len = j - i + 1;
            if(len > maxLen) {
                start = i;
                maxLen = len;
            }
        }

        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                solve(i, j, s, dp);
            }
        }

        return s.substr(start, maxLen);
    }
};
