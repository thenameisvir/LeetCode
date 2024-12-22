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
    bool mkcquestionki(TreeNode* root,long long int upperBound,long long int lowerBound){
        if(root==NULL){
            return true;
        }

        bool condition1 = (root->val>lowerBound);
        bool condition2 = (root->val<upperBound);

        bool left = mkcquestionki(root->left,root->val,lowerBound);
        bool right = mkcquestionki(root->right,upperBound,root->val);

        return condition1&&condition2&&left&&right;

    }
    bool isValidBST(TreeNode* root) {
        long long int upperBound = 2147483657;
        long long int lowerBound = -2147483657;

        return mkcquestionki(root,upperBound,lowerBound);
    }
};