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
    unordered_map<string,int>mp;
    vector<TreeNode*>ans;
    string solve(TreeNode* root){
        if(!root){
            return "N";
        }

        string curr = to_string(root->val);
        string left = solve(root->left);
        string right = solve(root->right);

        string final = curr + "," + left + "," + right;
        if(mp.find(final)!=mp.end()){
            if(mp[final]==1){
                ans.push_back(root);
                mp[final]++;
            }
        }
        else{
            mp[final] = 1;
        }

        return final;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};