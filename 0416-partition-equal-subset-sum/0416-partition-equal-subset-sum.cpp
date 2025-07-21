class Solution {
public:
    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (i >= nums.size() || target < 0) return false;

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool ans1 = solve(nums, i + 1, target - nums[i], dp);
        bool ans2 = solve(nums, i + 1, target, dp);

        return dp[i][target] = ans1 || ans2;
    }

    bool tab(vector<int>& nums){
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) count += nums[i];

        if (count % 2 != 0) return false;

        int target = count / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        // base case k according fill kia hai isko
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool inc = false;
                if(j-nums[i]>=0){
                inc = dp[i + 1][j - nums[i]];
                }
                 
                 bool exc = dp[i + 1][j];

                 dp[i][j] = inc || exc;
            }
        }

        return dp[0][target];


    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) count += nums[i];

        if (count % 2 != 0) return false;

        int target = count / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return tab(nums);
    }
};
