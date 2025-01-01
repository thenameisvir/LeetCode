class Solution {
public:
    TreeNode* buildTree(TreeNode* root, int num) {
        if (!root) {
            TreeNode* root = new TreeNode(num);
    return root;
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
        for (int i = 0; i < preorder.size(); i++) {
        root = buildTree(root, preorder[i]);
    }

        return root;
    }
};
