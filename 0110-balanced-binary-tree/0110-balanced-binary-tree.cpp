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
    int high(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int left = 1 + high(root->left);
        int right = 1 + high(root->right);


        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        // first we go with the base case of this function
        if(root==NULL){
            return true;
        }

        // now calculate the heights of the remaining 

        int left = high(root->left);
        int right = high(root->right);

        int diff = abs(left-right);

        bool ans = (diff<=1);

        if(!ans) return false;

        // now apply the recursion

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