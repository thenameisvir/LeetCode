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

    bool tab(vector<int>& nums){
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];

        if(sum%2!=0) return false;

        int target = sum/2;

        int n = nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

        for(int i = 0; i <= n; i++) dp[i][0] = true;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
            bool inc = false;
            if(j - nums[i] >= 0)
                inc = dp[i + 1][j - nums[i]];
            bool exc = dp[i + 1][j];

            dp[i][j] = inc||exc;
            }
        }

        return dp[0][target];

    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];

        if(sum%2!=0) return false;

        int target = sum/2;

        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        return tab(nums);
    }
};