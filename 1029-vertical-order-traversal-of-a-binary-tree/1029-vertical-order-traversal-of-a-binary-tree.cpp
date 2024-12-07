class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<TreeNode*, pair<int, int>>> q; // Node, {row, col}
        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> mp; // col -> {row: [x, y, z]};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode*& node = front.first;
            auto coordinate = front.second;

            int& row = coordinate.first;
            int& col = coordinate.second;
            mp[col][row].insert(node->val);

            if (node->left) q.push({node->left, {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }

        for (auto it : mp) {
            auto& colMap = it.second;
            vector<int> vLine;
            for (auto colMapIT : colMap) {
                auto& mset = colMapIT.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            v.push_back(vLine);
        }

        return v;
    }
};
