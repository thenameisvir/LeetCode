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
    TreeNode* vir = NULL;
    void findd(TreeNode* root, int target){
        if(root==NULL) return;

        if(target==root->val){ vir = root; return;}

        if(target>root->val){
            findd(root->right,target);
        }
        else{
            findd(root->left,target);
        }

        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        findd(root,val);
        return vir;
    }
};