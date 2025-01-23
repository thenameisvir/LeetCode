class Solution {
public:
    int solveUsingMemo(vector<int>& nums,int index,vector<int>&dp){
        // base case analyse kr
        if(index>=nums.size()){
            return 0; // kya hi chori karega tab bc
        }


        if(dp[index]!=-1){
            return dp[index];
        }


        // ek case solve karde
        int inc = nums[index] + solveUsingMemo(nums,index+2,dp);
        int exc = 0 + solveUsingMemo(nums,index+1,dp);

        int ans = max(inc,exc);
        dp[index] = ans;
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans = solveUsingMemo(nums,0,dp);
        return ans;
    }
};