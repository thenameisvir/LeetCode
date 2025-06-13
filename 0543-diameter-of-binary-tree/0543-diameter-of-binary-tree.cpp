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
    // maa ki chu is question ki 
    int height(TreeNode* root){
        if(!root) return 0;

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);


        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int sum = height(root->left) + height(root->right);

        return max(left,max(sum,right));
    }
};