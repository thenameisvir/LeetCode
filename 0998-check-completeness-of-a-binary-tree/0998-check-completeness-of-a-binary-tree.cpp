/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int LastNode = 0;
    int TotalNode = 0;

    void count(TreeNode* root) {
        if (!root) {
            return;
        }
        TotalNode++;
        count(root->left);
        count(root->right);
    }

    void countLast(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                LastNode++;
                q.push(current->left);
                q.push(current->right);
            } else {
                // If a NULL is encountered, remaining nodes should all be NULL
                while (!q.empty()) {
                    if (q.front() != nullptr) {
                        return;
                    }
                    q.pop();
                }
                break;
            }
        }
    }

    bool isCompleteTree(TreeNode* root) {
        count(root);
        countLast(root);

        return (LastNode == TotalNode);
    }
};
