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
    int ans = 0;
    int maxDepth(TreeNode* root) {
        // base case
        if(root==NULL){
            return 0;
        }

        int lefti = 1+ maxDepth(root->left);

        int righti = 1 + maxDepth(root->right);


        return max(lefti,righti);

    }
};