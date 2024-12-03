class Solution {
public:
    int D = 0; // Variable to store the maximum diameter

    int height(TreeNode* root) {
        if (root == NULL) return 0;

        // Recursively calculate the height of left and right subtrees
        int leftAns = height(root->left);
        int rightAns = height(root->right);

        // Update the diameter: left height + right height
        int currD = leftAns + rightAns;
        D = max(currD, D);

        // Return the height of the current node
        return 1 + max(leftAns, rightAns);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // Calculate height and update the diameter
        return D;     // Return the maximum diameter
    }
};
