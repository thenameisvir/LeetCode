class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        // base case would be 
        if(i>=nums.size()) return 0;

        // main case would be
        if(dp[i]!=INT_MIN) return dp[i];
        int inc = nums[i] + solve(nums,i+2,dp);
        int exc = 0 + solve(nums,i+1,dp);

        dp[i] =  max(inc,exc);

        return dp[i];
    }
    int tabulation(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n+1,0);

        dp[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
        int tempAns = 0;
        
        int inc = nums[i] + dp[i+2];
        int exc = 0 + dp[i+1];

        dp[i] = max(inc,exc);
        }
        return dp[0];
        }
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,INT_MIN);
        int ans = tabulation(nums);
        return ans;
    }
};