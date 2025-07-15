class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>&dp){

        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){

            int recAns = 0;
            if(amount>=coins[i]){
                recAns = solve(coins,amount-coins[i],dp);
                if(recAns!=INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini,ans);
                }
            }

        }

        return dp[amount] = mini;


    }
    int tab(vector<int>& coins, int amount){
        vector<int>dp(amount+1,-1);
        dp[0] = 0;
        for(int index = 1;index<=amount;index++){
            int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){

            int recAns = 0;
            if(index>=coins[i]){
                recAns = dp[index-coins[i]];
                if(recAns!=INT_MAX){
                    int ans = 1 + recAns;
                    mini = min(mini,ans);
                }
            }

        }

        dp[index] = mini;
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = tab(coins,amount);
        return (ans==INT_MAX)?-1:ans;
    }
};