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
        if(root==NULL){
            return 0;
        }

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);


        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        // base case
        if(root==NULL){
            return true;
        }

        // current Node ko solve karo 
        int left = height(root->left);
        int right = height(root->right);


        int diff = abs(left-right);

        bool ans =  (diff<=1);


        bool ans1 = isBalanced(root->left);
        bool ans2 = isBalanced(root->right);


        if(ans&&ans1&&ans2){
            return true;
        }
        else{
            return false;
        }

    }
};