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
    int h(TreeNode* root){
         if(root==NULL){
            return 0;
        }

        int left = 1+ h(root->left);

        int right = 1 + h(root->right);


        int height  = max(left,right);

        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;

        }

        int op1 = diameterOfBinaryTree(root->left);

        int op2 = diameterOfBinaryTree(root->right);

        int op3 = h(root->left) + h(root->right);


        int m = max(op1, max(op2,op3));


        return m;
    }
};