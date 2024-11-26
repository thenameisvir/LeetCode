class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return targetSum == root->val;

        bool ans1 = hasPathSum(root->left, targetSum - root->val);
        bool ans2 = hasPathSum(root->right, targetSum - root->val);

        return ans1 || ans2;
    }
};
