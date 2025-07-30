class Solution {
public:
    
    int tab(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= i; j++) {
            ans += dp[j - 1] * dp[i - j];
        }
        dp[i] = ans;
    }

    return dp[n];
}

    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return tab(n);
    }
};