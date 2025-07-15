class Solution {
public:
    void solve(vector<int>& ans, int n) {
        // Base cases
        ans[0] = 0;
        if (n >= 1) ans[1] = 1;

        // Fill the dp array using bottom-up approach
        for (int i = 2; i <= n; i++) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
    }

    int fib(int n) {
        if (n == 0) return 0;  // Edge case
        vector<int> ans(n + 1, 0);
        solve(ans, n);
        return ans[n];
    }
};
