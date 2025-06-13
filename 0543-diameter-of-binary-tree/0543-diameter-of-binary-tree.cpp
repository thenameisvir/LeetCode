class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0}; // {height, diameter}

        auto left = solve(root->left);
        auto right = solve(root->right);

        int currHeight = 1 + max(left.first, right.first);
        int diameterThroughRoot = left.first + right.first;
        int maxDiameter = max({left.second, right.second, diameterThroughRoot});

        return {currHeight, maxDiameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second;
    }
};
