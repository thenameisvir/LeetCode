class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v; // To store the result
        postorderHelper(root, v); // Call helper function
        return v; // Return the result
    }

private:
    void postorderHelper(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return; // Base case
        }

        postorderHelper(root->left, v);  // Traverse left subtree
        postorderHelper(root->right, v); // Traverse right subtree
        v.push_back(root->val);          // Add current node value
    }
};
