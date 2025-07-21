class Solution {
public:
    bool solve(vector<int>& nums,int i,int target,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(i>=nums.size() || target<0){
            return false;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        bool inc = solve(nums,i+1,target-nums[i],dp);
        bool exc = solve(nums,i+1,target,dp);

        return dp[i][target] = inc||exc;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];

        if(sum%2!=0) return false;

        int target = sum/2;

        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        return solve(nums,0,target,dp);
    }
};