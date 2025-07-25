class Solution {
public:
    const int MOD = 1e9 + 7;

    int tab(string s, string t){
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for(int i = 0; i <= n; i++){
            dp[i][m] = 1;  // If t is empty
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                long long inc = 0, exc = 0;
                if(s[i] == t[j]){
                    inc = dp[i + 1][j + 1];
                }
                exc = dp[i + 1][j];

                dp[i][j] = (inc + exc) % MOD;
            }
        }

        return dp[0][0]; // Final answer
    }

    int numDistinct(string s, string t) {
        return tab(s, t);
    }
};
