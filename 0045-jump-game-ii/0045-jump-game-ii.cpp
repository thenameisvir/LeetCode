class Solution {
public:
    int solve(vector<int>& nums,int i,int n,vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        // pehla base case ho chuka hai 
        if(nums[i]==0) return 1e9;
        // doosra bhi easy tha bilkul coin change ki tarha 
        if(dp[i]!=-1) return dp[i];

        // ab main case 
        int mini = 1e9;
        for(int m=1;m<=nums[i];m++){
            mini = min(mini,1+solve(nums,i+m,n,dp));
        }

        dp[i] = mini;
        return dp[i];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(nums.size(),-1);
        int ans = solve(nums,0,n,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};