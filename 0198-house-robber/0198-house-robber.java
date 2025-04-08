class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-1);
        // return helper(nums,nums.length-1);
        // return memo(nums,dp,nums.length-1);
        return tabu(nums,dp,nums.length-1);
    }

    int helper(int[] nums,int n){
        if(n == 0) return nums[0];
        if(n<0) return 0;
        
        //pick
        int steel = nums[n]+helper(nums,n-2);
        
        //not pick
        int notsteel = helper(nums,n-1);
        
        return Math.max(steel,notsteel);
    }

    int memo(int[] nums,int[] dp,int n){
        if(n == 0) return nums[0];
        if(n<0) return 0;
        
        //pick
        int steel = nums[n]+helper(nums,n-2);
        
        //not pick
        int notsteel = helper(nums,n-1);
        
        dp[n] = Math.max(steel,notsteel);
        return dp[n];
    }

    int tabu(int[] nums,int[] dp,int n){
        if(n == 0) return nums[0];
        if(n<0) return 0;

        dp[0] = nums[0];

        for(int i=1;i<=n;i++){
            int pick = nums[i]+ ((i>1)? dp[i-2]:0);
            int notpick = dp[i-1];
            dp[i] = Math.max(pick,notpick);
        }

        return dp[n];
    }

    int spaceop(int[] nums,int n){
        if(n==0) return nums[0];
        if(n<0) return 0;
        int dp = nums[0];
        int prev =0;

        for(int i=1;i<=n;i++){
            int pick = nums[i]+ ((i>1)? prev:0);
            int notpick = prev;
            int temp = Math.max(pick,notpick);
            dp=prev;
            prev = temp;
        }

        return prev;
    }
}