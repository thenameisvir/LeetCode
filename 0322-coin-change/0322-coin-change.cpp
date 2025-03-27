class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>&dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        // base case ho gaye hai ab main case

        if(dp[amount]!=-1) return dp[amount];
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int recAns;

            if(coins[i]>amount){
                recAns = INT_MAX;
            }

            recAns = solve(coins,amount-coins[i],dp);
            if(recAns!=INT_MAX){
                int temp = 1 + recAns;
                mini = min(temp,mini);
            }

            
        }
        dp[amount] = mini;

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = solve(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};