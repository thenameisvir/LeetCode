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
    int rob(vector<int>& nums) {
        int index = 0;
        vector<int>dp(nums.size(),-1);
        int ans = solveebymemoisation(nums,index,dp);
        return ans;
    }
};