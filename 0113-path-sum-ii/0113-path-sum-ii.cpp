class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> &temp, int sum) {
        if (root == NULL) return;

        // Add current node value to sum and path
        sum += root->val;
        temp.push_back(root->val);

        // Check if it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                ans.push_back(temp);
            }
        } else {
            // Recur for left and right children
            solve(root->left, targetSum, ans, temp, sum);
            solve(root->right, targetSum, ans, temp, sum);
        }

        // Backtrack: remove the current node from the path
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, ans, temp, 0);
        return ans;
    }
};
