class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;  // To store the result
        preorderHelper(root, v);  // Call helper function
        return v;  // Return the result
    }

private:
    void preorderHelper(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;  // Base case
        }

        v.push_back(root->val);        // Add current node value
        preorderHelper(root->left, v); // Traverse left subtree
        preorderHelper(root->right, v); // Traverse right subtree
    }
};
