class Solution {
public:
    int searchInorder(vector<int>& inorder, int size, int target) {
        for (int i = 0; i < size; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, int size) {
        // Base case
        if (preIndex >= size || inStart > inEnd) return nullptr;

        // Solve 1 case
        int e = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(e);

        // Find the element in inorder
        int position = searchInorder(inorder, size, e);

        // Recursion for left and right subtrees
        root->left = construct(preorder, inorder, preIndex, inStart, position - 1, size);
        root->right = construct(preorder, inorder, preIndex, position + 1, inEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preIndex = 0;
        int inStart = 0;
        int inEnd = size - 1;

        // Start building the tree
        return construct(preorder, inorder, preIndex, inStart, inEnd, size);
    }
};