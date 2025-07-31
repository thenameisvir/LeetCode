class Solution {
public:
    int solve(TreeNode* root, bool canRob, unordered_map<TreeNode*, pair<int, int>>& dp) {
        if (!root) return 0;

        if (canRob && dp.find(root) != dp.end() && dp[root].second != -1)
            return dp[root].second;

        if (!canRob && dp.find(root) != dp.end() && dp[root].first != -1)
            return dp[root].first;

        int robThis = 0, skipThis = 0;

        if (canRob) {
            robThis = root->val + solve(root->left, false, dp) + solve(root->right, false, dp);
        }

        skipThis = solve(root->left, true, dp) + solve(root->right, true, dp);

        int result = max(robThis, skipThis);

        if (dp.find(root) == dp.end())
            dp[root] = {-1, -1};

        if (canRob)
            dp[root].second = result;
        else
            dp[root].first = result;

        return result;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> dp;
        return solve(root, true, dp);
    }
};
