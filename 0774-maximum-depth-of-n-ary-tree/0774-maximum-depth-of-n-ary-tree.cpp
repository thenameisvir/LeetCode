class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;  // Base case: If root is null, depth is 0

        int depth = 0;
        for (Node* child : root->children) {
            depth = max(depth, maxDepth(child));  // Find max depth among children
        }

        return 1 + depth;  // Include current node in depth count
    }
};
