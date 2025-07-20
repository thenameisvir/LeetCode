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
    int tab(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int inc = 0;
            if(j==-1 || nums[i]>nums[j]){
                inc = 1 + dp[i+1][i+1];
            }
            int exc = 0 + dp[i+1][j+1];

             dp[i][j+1] =  max(inc,exc);
            }
        }

    return dp[0][0];

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return tab(nums);
    }
};