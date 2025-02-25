class Solution {
public:
    int count = 0;
    
    bool isSafe(int x, int y, vector<vector<int>>& arr, map<pair<int, int>, bool>& vis) {
        if (x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && !vis[{x, y}] && arr[x][y] == 1) {
            return true;
        }
        return false;
    }

    void bfs(vector<vector<int>>& arr, map<pair<int, int>, bool>& vis, queue<pair<int, int>>& q) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            while (size--) {
                auto topPair = q.front();
                int tempx = topPair.first;
                int tempy = topPair.second;
                q.pop();  // ✅ Queue se remove karna zaroori hai

                for (int i = 0; i < 4; i++) {
                    int newX = tempx + dx[i];
                    int newY = tempy + dy[i];

                    if (isSafe(newX, newY, arr, vis)) {
                        q.push({newX, newY});
                        vis[{newX, newY}] = true;
                        arr[newX][newY] = 2; // ✅ Fresh orange ko rotten mark karo
                        rotted = true;
                    }
                }
            }
            if (rotted) count++; // ✅ Sirf ek level ke baad increment karna hai
        }
    }

    int orangesRotting(vector<vector<int>>& arr) {
        map<pair<int, int>, bool> vis;
        queue<pair<int, int>> q;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                if (arr[i][j] == 2) {
                    q.push({i, j});
                    vis[{i, j}] = true;
                }
            }
        }

        bfs(arr, vis, q);
        
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                if (arr[i][j] == 1) return -1; // ✅ Agar fresh orange bacha hai toh -1 return karo
            }
        }

        return count;
    }
};
