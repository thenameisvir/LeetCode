class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;

                // Find the rightmost node in the left subtree or stop if it already points to curr
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {
                    // Establish the thread and move to the left child
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove the thread, process the current node, and move to the right child
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
