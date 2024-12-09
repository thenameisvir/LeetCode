class Solution {
public:
    int ansSum(TreeNode* root, long long targetSum) {
        if (!root) return 0;

        int count = 0;

        // Check if current node completes a path
        if (root->val == targetSum) {
            count = 1;
        }

        // Continue checking in left and right subtrees
        count += ansSum(root->left, targetSum - root->val);
        count += ansSum(root->right, targetSum - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        // Count paths starting from the current node
        int count = ansSum(root, targetSum);

        // Count paths in left and right subtrees
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};
