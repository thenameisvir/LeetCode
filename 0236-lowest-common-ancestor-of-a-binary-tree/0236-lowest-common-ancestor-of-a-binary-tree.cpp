/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // These are the base cases for the following
        if(root==NULL) return NULL;
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;

        //initialise the recursion functions 
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // now the three mandatory checking conditions
        if(!left && !right) return NULL;
        else if(left && !right) return left;
        else if(!left && right) return right;
        else return root;

    }
};