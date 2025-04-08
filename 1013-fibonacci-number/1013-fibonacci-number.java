class Solution {
    public int fib(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        // return memo(n,dp);
        // return tabu(n,dp);
        return spaceop(n); 
    }

    int memo(int n, int[] dp){
        if(n==1 || n==0){
            return n;
        }

        if(dp[n]!=-1) return dp[n];
        return dp[n] = fib(n-1)+fib(n-2);
    }

    int tabu(int n,int[] dp){
        if(n==1 || n==0) return n;
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int spaceop(int n){
        if(n==0 || n==1) return n;
        int fib0 = 0; 
        int fib1 = 1;

        for(int i=2;i<=n;i++){
            int temp = fib0+fib1;
            fib0 = fib1;
            fib1 = temp;
        } 

        return fib1;
    }
}