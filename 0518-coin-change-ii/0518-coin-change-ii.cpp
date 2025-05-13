class Solution {
public:
    int solve(int amount, vector<int>& coins,int i,vector<vector<int>>&dp){
        // find all possible ways me mai pehle bhi fas chuka hu isme base case bhot imp h
        if(i>=coins.size() || amount<0) return 0;
        if(amount==0) return 1;
        
        if(dp[amount][i]!=-1){
            return dp[amount][i];
        }

        // isme ab apan include aur exclude lagayenge
        int inc = solve(amount-coins[i],coins,i,dp);
        int exc = solve(amount,coins,i+1,dp);

        return dp[amount][i] = inc+exc;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans = solve(amount,coins,0,dp);
        return ans;
    }
};