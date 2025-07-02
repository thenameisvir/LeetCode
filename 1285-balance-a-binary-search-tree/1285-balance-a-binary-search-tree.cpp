class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    TreeNode* okay(vector<int>& ans, int s, int e) {
        if(s > e) return NULL;
        int m = s + (e - s) / 2;
        TreeNode* newNode = new TreeNode(ans[m]);
        newNode->left = okay(ans, s, m - 1);
        newNode->right = okay(ans, m + 1, e);
        return newNode;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return okay(ans, 0, ans.size() - 1);
    }
};
