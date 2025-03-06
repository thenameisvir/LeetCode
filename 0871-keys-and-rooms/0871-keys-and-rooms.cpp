class Solution {
public:
    void bfs(unordered_map<int,bool>& vis, unordered_map<int, list<int>>& adj, queue<int>& q) {
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto i : adj[front]) {
                if (!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& arr) {
        unordered_map<int, list<int>> adj;
        int n = arr.size(); // total number of rooms

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                adj[i].push_back(arr[i][j]);
                // DO NOT add reverse edge: this is a directed graph (keys only work in one direction)
            }
        }

        unordered_map<int, bool> vis;
        queue<int> q;
        q.push(0);
        vis[0] = true;

        bfs(vis, adj, q);

        // Check if all rooms are visited
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
};
