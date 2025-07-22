class Solution {
public:
    long long int MOD = 1000000007;
    int solve(int n, int sum, int k, int target,vector<vector<int>>&dp){
        // base cases
        if(n == 0 && sum == target) return 1;
        if(n == 0 || sum > target) return 0;

        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }

        int ans = 0;
        for(int i = 1; i <= k; i++){
            int recAns = 0;
            if(sum+i <= target)
                recAns =  (solve(n - 1, sum + i, k, target,dp)) % MOD;
            ans = (ans%MOD  + recAns%MOD) % MOD;
        }

        return dp[n][sum] =  ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n, 0, k, target,dp);
    }
};
