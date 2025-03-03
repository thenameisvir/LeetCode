class Solution {
public:
    void bfs(vector<vector<char>>& arr, vector<vector<bool>>& vis, queue<pair<int, int>>& q) {
        int n = arr.size(), m = arr[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] && arr[newx][newy] == 'O') {
                    vis[newx][newy] = true;
                    arr[newx][newy] = '#'; // Temporarily mark boundary-connected 'O'
                    q.push({newx, newy});
                }
            }
        }
    }

    void solve(vector<vector<char>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        // **Step 1: Push Boundary 'O' into Queue**
        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 'O') {
                q.push({i, 0});
                vis[i][0] = true;
                arr[i][0] = '#';
            }
            if (arr[i][m - 1] == 'O') {
                q.push({i, m - 1});
                vis[i][m - 1] = true;
                arr[i][m - 1] = '#';
            }
        }
        for (int j = 0; j < m; j++) {
            if (arr[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = true;
                arr[0][j] = '#';
            }
            if (arr[n - 1][j] == 'O') {
                q.push({n - 1, j});
                vis[n - 1][j] = true;
                arr[n - 1][j] = '#';
            }
        }

        // **Step 2: BFS from Boundary**
        bfs(arr, vis, q);

        // **Step 3: Convert Remaining 'O' -> 'X' and '#' -> 'O'**
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 'O') {
                    arr[i][j] = 'X'; // Isolated 'O' -> 'X'
                } else if (arr[i][j] == '#') {
                    arr[i][j] = 'O'; // Boundary-connected 'O' -> 'O' (restore)
                }
            }
        }
    }
};
