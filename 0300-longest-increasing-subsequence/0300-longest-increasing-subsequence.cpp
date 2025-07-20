class Solution {
public:
    int solve(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }

        if(dp[curr][prev+1]!=0){
            return dp[curr][prev+1];
        }

        int inc = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            inc = 1 + solve(nums,curr+1,curr,dp);
        }
        int exc = 0 + solve(nums,curr+1,prev,dp);

        return dp[curr][prev+1] =  max(inc,exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return solve(nums,0,-1,dp);
    }
};