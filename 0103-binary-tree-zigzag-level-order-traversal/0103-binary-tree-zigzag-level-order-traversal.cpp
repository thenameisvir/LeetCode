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
        // Base cases are more important than the logic haha
        vector<vector<int>>v;
        if(!root) return v;
        // Initial condition to give the stage to the logic
        queue<TreeNode*>q;
        q.push(root);
        bool LtoR = true;
        while(!q.empty()){

            int width = q.size();
            vector<int>v2(width);

            // now traverse on the queue to fill the 1D vector
            for(int i=0;i<width;i++){
                // Take the front node and do operations accordingly
                TreeNode* front = q.front();q.pop();
                // we need to specify the index accordingly
                int index = LtoR ? i : width - i - 1;
                // state the value into the vector
                v2[index] = front->val;

                // now to maintain the queue , push all the children into it

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);


            }


            // Now you need to toggle the boolean
            LtoR = !LtoR;

            v.push_back(v2);

        }


        return v;

    }
};