class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;  // To store the result
        if (root == nullptr) {
            return result;  // If the tree is empty, return an empty result
        }

        queue<TreeNode*> q;  // Queue to store nodes at each level
        q.push(root);  // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            vector<int> currentLevel;  // To store nodes at the current level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();  // Remove the node from the queue
                currentLevel.push_back(node->val);  // Add the node value to current level

                // Add left and right children to the queue for the next level
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(currentLevel);  // Add the current level to the result
        }

        return result;  // Return the result
    }
};
