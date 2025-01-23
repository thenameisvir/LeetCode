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
        // return max(inc,exc);
        int ans = max(inc,exc);
        dp[index] = ans;
        return dp[index];
    }
    int solveByTabulation(vector<int>& nums){
        vector<int>dp(nums.size()+1,0);
        int n = nums.size();
        // ek ans dalna padega humko somehow
        dp[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
        int inc = nums[i] + dp[i+2];
        int exc = 0 + dp[i+1];

        dp[i] = max(inc,exc);
        }

        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans = solveByTabulation(nums);
        return ans;
    }
};