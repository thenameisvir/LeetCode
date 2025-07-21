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

        
        vector<bool>curr(target+1,false);
        vector<bool>prev(target+1,false);
        // base case k according fill kia hai isko
        curr[0] = true;
        prev[0] = true;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool inc = false;
                if(j-nums[i]>=0){
                inc = prev[j - nums[i]];
                }
                 
                 bool exc = prev[j];

                 curr[j] = inc || exc;
            }
            prev = curr;
        }

        return curr[target];


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
