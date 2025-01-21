class Solution {
public:
    int solveUsingMem(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }
        // just base case k baad step no 3
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);

        return dp[n];
    }
    int fib(int n) {
        // create a dp array and do understand that you are doing solution upto n
        // so make upto it only 

        vector<int>dp(n+1,-1);
        int ans = solveUsingMem(n,dp);
        return ans;
        
    }
};