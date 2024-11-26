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
    bool hasPathSum(TreeNode* root, int targetSum) {
// my first case for the path sum is , if i have tackeled the null node then
        if(root==NULL) return false;
// my second case if for the leaf node because then i have to check the conditions
        if(root->left==NULL && root->right==NULL) return targetSum==root->val;


        // now the recursion conditions
        bool ans1 = hasPathSum(root->left,targetSum-root->val);
        bool ans2 = hasPathSum(root->right,targetSum-root->val);


        return ans1||ans2;
    }
};