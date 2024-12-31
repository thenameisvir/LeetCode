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
    TreeNode* okayokay2(vector<int>& nums,int s,int e){
        if(s>e) return NULL;

        int m = s+(e-s)/2;
        TreeNode* root = new TreeNode(nums[m]);

        root->left = okayokay2(nums,s,m-1);
        root->right = okayokay2(nums,m+1,e);


        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        return okayokay2(nums,s,e);
    }
};