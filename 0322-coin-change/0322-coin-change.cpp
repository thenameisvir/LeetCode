class Solution {
public:
    int solve(vector<int>& coins, int amount,int i,vector<vector<int>>&dp){
        if(i>=coins.size() || amount<0){
            return 1e9;
        }
        if(amount==0){
            return 0;
        }
        if(dp[amount][i]!=-1){
            return dp[amount][i];
        }
        int inc = 1 + solve(coins,amount-coins[i],i,dp);
        int exc = 0 + solve(coins,amount,i+1,dp);

        return dp[amount][i] = min(inc,exc);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans = solve(coins,amount,0,dp);
        return (ans==1e9)?-1:ans;
    }
};