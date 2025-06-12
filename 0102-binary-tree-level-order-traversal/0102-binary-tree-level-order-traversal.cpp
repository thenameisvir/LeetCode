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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Using NULL concept
        vector<vector<int>>result;
        if(!root) return result;
        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);
        
        vector<int>v;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp==NULL){
                result.push_back(v);
                v.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                v.push_back(temp->val);

                // bs children ko queue me push karna hai 
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return result;
    }
};