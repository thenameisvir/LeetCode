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
    bool solve(TreeNode* root, int targetSum,int sum){
        if(root==NULL) return false;
// if(root->left==NULL && root->right==NULL) return sum==targetSum;
        if (root->left == NULL && root->right == NULL) return (sum + root->val) == targetSum;
        


        bool ans1 = solve(root->left,targetSum,sum + root->val);
        bool ans2 = solve(root->right,targetSum,sum + root->val);


        return ans1||ans2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root,targetSum,sum);

        return ans;
    }
};