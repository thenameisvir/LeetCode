class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> res(n, 0);         
        vector<int> subtree_count(n, 1); 

        
        function<void(int, int)> postOrder = [&](int node, int parent) {
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                postOrder(neighbor, node);
                subtree_count[node] += subtree_count[neighbor];
                res[node] += res[neighbor] + subtree_count[neighbor];
            }
        };
        
        postOrder(0, -1);
        function<void(int, int)> preOrder = [&](int node, int parent) {
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
               
                res[neighbor] = res[node] - subtree_count[neighbor] + (n - subtree_count[neighbor]);
                preOrder(neighbor, node);
            }
        };

        preOrder(0, -1); 

        return res;
    }
};
