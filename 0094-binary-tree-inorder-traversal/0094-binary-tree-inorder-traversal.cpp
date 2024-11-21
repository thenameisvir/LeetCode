class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;  // To store the result
        inorderHelper(root, v);  // Call helper function
        return v;  // Return the result
    }

private:
    void inorderHelper(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;  // Base case
        }

        inorderHelper(root->left, v);  // Traverse left subtree
        v.push_back(root->val);        // Add current node value
        inorderHelper(root->right, v); // Traverse right subtree
    }
};
