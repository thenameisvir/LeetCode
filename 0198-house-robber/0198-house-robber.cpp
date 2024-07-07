class Solution {
public:
    int solveusingrec(vector<int>& nums, int index) {
        // base case
        if (index >= nums.size()) {
            return 0;
        }
        int include = nums[index] + solveusingrec(nums, index + 2);
        int exclude = solveusingrec(nums, index + 1);
        return max(include, exclude);
    }

    int solvebyMemoisation(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int include = nums[index] + solvebyMemoisation(nums, index + 2, dp);
        int exclude = solvebyMemoisation(nums, index + 1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }
    // tabulation
    int solveusingtab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[n-1] = nums[n-1];
        for(int index = n-2;index>=0;index--){
            int tempans = 0;
            if(index+2<n){
                tempans = dp[index+2];
            }
            
            int include = nums[index] + tempans;
            int exclude = dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        
        // int ans = solveusingrec(nums, index);
        // return ans;

        // Memoization approach
        int n = nums.size();
        // vector<int> dp(n, -1);
        int ans = solveusingtab(nums);
        return ans;
    }
};
