class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val % 2 == 0) {
                if (front->left) {
                    if (front->left->left) sum += front->left->left->val;
                    if (front->left->right) sum += front->left->right->val;
                }
                if (front->right) {
                    if (front->right->left) sum += front->right->left->val;
                    if (front->right->right) sum += front->right->right->val;
                }
            }

            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }

        return sum;
    }
};
