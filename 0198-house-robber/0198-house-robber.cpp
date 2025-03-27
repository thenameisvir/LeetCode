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
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,INT_MIN);
        int ans = solve(nums,0,dp);
        return ans;
    }
};