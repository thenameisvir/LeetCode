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
    void BuildIt(TreeNode* root,vector<int>&v){
        if(!root){
            return;
        }

        BuildIt(root->left,v);
        v.push_back(root->val);
        BuildIt(root->right,v);
    }
    TreeNode* solve(TreeNode* &moot,vector<int>v,int s,int e){
        if(s>e) return NULL;

        int m = s+(e-s)/2;

        TreeNode* root = new TreeNode(v[m]);

        root->left = solve(moot,v,s,m-1);
        root->right = solve(moot,v,m+1,e);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        BuildIt(root,v);
        TreeNode* moot = NULL;

        int s = 0;
        int e = v.size()-1;
    
        moot = solve(moot,v,s,e);
        return moot;


    }
};