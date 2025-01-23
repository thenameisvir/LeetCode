class Solution {
public:
    int solveUsingRec(vector<int>& coins, int amount){
        // base case baad me 
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        // ek case tu kar baki mai sambhal lunga
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int recAns = 0;
            if(amount-coins[i]>=0){
                recAns = solveUsingRec(coins,amount-coins[i]);
                if(recAns!=INT_MAX){
                    int ans = recAns +1;
                    mini = min(mini,ans);
                }
            }
        }

        return mini;
    }
    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
        //base case
        if(amount == 0) {
            return 0;
        }
        //already ans exist
        if(dp[amount] != -1) {
            return dp[amount];
        }
        //recursive relation
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            //find ans using ith coin
            //call recursion only for valid amounts i.e. >=0  wale amounts
            if(amount - coins[i] >= 0) {
                int recursionKaAns = solveUsingMem(coins, amount - coins[i], dp);
                //if a valid answeer
                if(recursionKaAns != INT_MAX) {
                    //considering uage of ith coin
                    int ans = 1 + recursionKaAns;
                    mini  = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

        
    }
};