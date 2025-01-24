class Solution {
public:
    int usingMemo(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        // second base case sochenge abhi
        if(amount<0){
            return INT_MAX;
        }
        // change kya ho rha hai amount change ho raha hai
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini = INT_MAX;
         for(int i=0;i<coins.size();i++){
            // yaha ayega main logic
            
            int recAns;
            if(amount<coins[i]){
                recAns = INT_MAX;
            }

            recAns = usingMemo(coins,amount-coins[i],dp);
            
            if(recAns!=INT_MAX){
                int ans = 1 + recAns;
                mini = min(ans,mini);
            }
        }

        dp[amount] = mini;
        return dp[amount];


    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = usingMemo(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};