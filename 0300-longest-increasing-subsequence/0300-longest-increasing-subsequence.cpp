class Solution {
public:
    int usingRec(vector<int>& nums,int curr,int prev){
        if(curr>=nums.size()) return 0;

        // calculate one ans only 

        int inc = 0, exc = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            inc = 1 + usingRec(nums,curr+1,curr);
        }
        exc = 0 + usingRec(nums,curr+1,prev);

        return max(inc,exc);
    }
    int usingTab(vector<int>& nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=nums.size()) return 0;

        if(dp[curr][prev+1] != -5) return dp[curr][prev+1];

        int inc = 0, exc = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            inc = 1 + usingTab(nums,curr+1,curr,dp);
        }
        exc = 0 + usingTab(nums,curr+1,prev,dp);

        dp[curr][prev+1] = max(inc, exc);
return dp[curr][prev+1];


    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-5));
        int ans  = usingTab(nums,0,-1,dp); return ans;
    }
};