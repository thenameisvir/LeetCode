class Solution {
public:
    int usingRec(int n){
        // base case baad me likhenge 
        if(n==0 || n==1){
            return n;
        }

        // ek case tum sambhalo baki recursion dekh lega 
        int ans = usingRec(n-1) + usingRec(n-2);

        return ans;

    }
    int usingMemoization(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }
        // base case remains the same


        // ek case tum kardo madhur bhai baki mai hu na store kr lunga 
        if(dp[n]!=-1){
            return dp[n];
        }

        int ans = usingMemoization(n-1,dp) + usingMemoization(n-2,dp);

        dp[n] = ans;
        return dp[n];

    }
    int usingSpaceOP(int n){
        // behencho isme vector lenge hi kyu ye bata 
        return -1;
        
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans1 = usingRec(n);
        int ans2 = usingMemoization(n,dp);
        return ans2;
    }
};