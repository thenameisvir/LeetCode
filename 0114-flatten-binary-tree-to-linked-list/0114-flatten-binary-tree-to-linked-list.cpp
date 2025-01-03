class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the right subtree
        TreeNode* temp = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;

        // Find the end of the new right subtree
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }

        // Attach the previously stored right subtree
        current->right = temp;
    }
};
