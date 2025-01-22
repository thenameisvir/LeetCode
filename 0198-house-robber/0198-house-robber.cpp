class Solution {
public:
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        //step1
        vector<int> dp(n, -1);
        //step2
        dp[n-1] = nums[n-1];
        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int ans = solveUsingTabulation(nums);
        return ans;
    }
};