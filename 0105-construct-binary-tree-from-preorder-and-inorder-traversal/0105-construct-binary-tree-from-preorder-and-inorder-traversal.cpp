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
    int search(vector<int>& inorder, int size, int num) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == num) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructfromPreandIn(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, int size) {
        // Base Case
        if (preIndex >= size || inStart > inEnd) {
            return NULL;
        }

        // Convert the current preorder element to a node
        int element = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(element);

        // Search for the element in the inorder array
        int position = search(inorder, size, element);

        // Recursive calls for left and right subtrees
        root->left = constructfromPreandIn(preorder, inorder, preIndex, inStart, position - 1, size);
        root->right = constructfromPreandIn(preorder, inorder, preIndex, position + 1, inEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preIndex = 0;
        int inStart = 0;
        int inEnd = size - 1;

        return constructfromPreandIn(preorder, inorder, preIndex, inStart, inEnd, size);
    }
};
