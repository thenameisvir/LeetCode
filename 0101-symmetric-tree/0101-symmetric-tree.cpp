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
    void check1(TreeNode* root,vector<int>&v1){
        if(!root){
            v1.push_back(-1);
            return;
        }

        v1.push_back(root->val);
        check1(root->left,v1);
        check1(root->right,v1);
    }
    void check2(TreeNode* root,vector<int>&v2)
    {
        if(!root){
            v2.push_back(-1);
            return;
        }

        v2.push_back(root->val);
        check2(root->right,v2);
        check2(root->left,v2);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        vector<int>v1;
        vector<int>v2;
        check1(root->left,v1);
        check2(root->right,v2);

        return v1==v2;
    }
};