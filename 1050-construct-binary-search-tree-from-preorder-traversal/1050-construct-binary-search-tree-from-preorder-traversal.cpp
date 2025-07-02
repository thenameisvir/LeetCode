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
    TreeNode* solve(int data,TreeNode* &root){
        if(!root){
            TreeNode* newNode = new TreeNode(data);
            return newNode;
        }
        else{
            if(data>root->val){
                root->right = solve(data,root->right);
            }
            else{
                root->left = solve(data,root->left);
            }
        }

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        TreeNode* root = NULL;
        for(int i=0;i<arr.size();i++){
            root = solve(arr[i],root);
        }

        return root;
    }
};