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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>vir;
        queue<TreeNode*>q;
        if(!root) return vir;
        // initial state maintain krte hai chalo 
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode* front = q.front(); q.pop();
                int index = flag ? i : size-i-1;
                temp[index] = front->val;
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            // yaha par flag ko update karna mat bhulna tu 
            flag = !flag;

            // ab main vector me push kardo 
            vir.push_back(temp);
        }

        return vir;
    }
};