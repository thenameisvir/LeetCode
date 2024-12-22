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
        TreeNode* ans = NULL;
        if(root==NULL) return ans;

        while(root){
            if(root->val==p->val){
                ans = p;
                break;
            }
            if(root->val==q->val){
                ans = q;
                break;
            }

            if(root->val>p->val && root->val>q->val){
                root = root->left;
            }
            else if(root->val<p->val && root->val<q->val){
                root = root->right;
            }
            else if(root->val>p->val && root->val<q->val){
                ans = root;
                break;
            }
            else{
                ans = root;
                break;
            }
        }


        return ans;
    }
};