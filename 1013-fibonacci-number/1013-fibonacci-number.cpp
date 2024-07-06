class Solution {
public:
    int SolveusingMemo(int n, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = SolveusingMemo(n-1, dp) + SolveusingMemo(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        if (n < 2) return n; 
        vector<int> dp(n + 1, -1);
        int ans = SolveusingMemo(n, dp);
        return ans;
    }
};
