class Solution {
public:
    TreeNode* buildTree(TreeNode* root, int num) {
        if (!root) {
            return new TreeNode(num);
        }

        if (num > root->val) {
            root->right = buildTree(root->right, num);
        } else {
            root->left = buildTree(root->left, num);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (int num : preorder) {
            root = buildTree(root, num);
        }

        return root;
    }
};
