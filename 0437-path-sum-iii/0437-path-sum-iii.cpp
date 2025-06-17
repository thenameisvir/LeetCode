class Solution {
public:
    bool check(TreeNode* root, long long target, long long sum, int &ans){
        if(!root){
            return false;
        }

        sum += root->val;
        if(sum == target){
            ans++;
        }

        bool left = check(root->left, target, sum, ans);
        bool right = check(root->right, target, sum, ans);

        return left || right;
    }

    void isTree(TreeNode* root, long long target, int& ans){
        if(!root){
            return;
        }

        long long sum = 0;
        check(root, target, sum, ans);

        isTree(root->left, target, ans);
        isTree(root->right, target, ans);
    }

    int pathSum(TreeNode* root, int target) {
        int ans = 0;
        isTree(root, (long long)target, ans);
        return ans;
    }
};
