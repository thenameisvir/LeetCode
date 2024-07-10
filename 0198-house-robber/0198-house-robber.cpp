class Solution {
public:
    int solvebyrecursion(vector<int>&nums,int index){
        if(index>=nums.size()) return 0;

        // logic of include
        int include = nums[index] + solvebyrecursion(nums,index+2);
        // logic of exclude
        int exclude = 0 + solvebyrecursion(nums,index+1);

        int pa = max(include,exclude);
        return pa;
    }
    int solveebymemoisation(vector<int>& nums,int index,vector<int>&dp){
        if(index>=nums.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        // logic of include
        int include = nums[index] + solveebymemoisation(nums,index+2,dp);
        // logic of exclude
        int exclude = 0 + solveebymemoisation(nums,index+1,dp);

        dp[index] = max(include,exclude);

        return dp[index];

    }
    int solvebytabulation(vector<int>& nums){
    
        if(nums.size()<=0) return 0;
        int n = nums.size();
        vector<int>dp(nums.size(),-1);

        dp[n-1] = nums[n-1];

        for(int index = n-2;index>=0;index--){
            int tempans = 0;
            if(index+2<n){
                tempans = dp[index+2];
            }
            int include = nums[index] + tempans;
            // logic of exclude
            int exclude = 0 + dp[index+1];

            dp[index] = max(include,exclude);
        }

        return dp[0];
        
        
    }
    int rob(vector<int>& nums) {
        int index = 0;
        vector<int>dp(nums.size(),-1);
        int ans = solvebytabulation(nums);
        return ans;
    }
};