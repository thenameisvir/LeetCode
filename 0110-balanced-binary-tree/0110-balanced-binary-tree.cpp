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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);

        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true; // Ye toh obvious hai ki agar null hua toh balanced h

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        int diff = abs(height(root->left) - height(root->right));
        bool final = diff<=1;

        if(left && right && final){
            return true;
        }

        return false;
    }
};