class Solution {
public:
    int count = 0;

    bool isSafe(int x, int y, map<pair<int, int>, bool>& vis, vector<vector<int>>& arr) {
        if (x < arr.size() && y < arr[x].size() && vis.find({x, y}) == vis.end() && arr[x][y] == 1) {
            return true;
        }
        return false;
    }

    void solve(map<pair<int, int>, bool>& vis, queue<pair<int, int>>& q, vector<vector<int>>& arr, int i, int j) {
        vis[{i, j}] = true;
        q.push({i, j});
        
        count = 1;  // ✅ Count reset for each island

        while (!q.empty()) {
            auto topPair = q.front();
            int tempx = topPair.first;
            int tempy = topPair.second;
            q.pop();

            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};

            for (int d = 0; d < 4; d++) {
                int newx = tempx + dx[d];
                int newy = tempy + dy[d];

                if (isSafe(newx, newy, vis, arr)) {
                    vis[{newx, newy}] = true;
                    q.push({newx, newy});
                    count += 1;  // ✅ Increment island size correctly
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& arr) {
        map<pair<int, int>, bool> vis;
        queue<pair<int, int>> q;
        int maxCount = 0;  // ✅ Maintain max area

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (vis.find({i, j}) == vis.end() && arr[i][j] == 1) {
                    count = 0;  // ✅ Reset before processing new island
                    solve(vis, q, arr, i, j);
                    maxCount = max(maxCount, count);  // ✅ Track largest island
                }
            }
        }
        return maxCount;
    }
};
