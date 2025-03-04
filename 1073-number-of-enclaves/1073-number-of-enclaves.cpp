#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // Boundary par 1s ko queue me daalo aur mark karo
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) q.push({i, 0}), vis[i][0] = true;
            if (grid[i][n - 1] == 1) q.push({i, n - 1}), vis[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) q.push({0, j}), vis[0][j] = true;
            if (grid[m - 1][j] == 1) q.push({m - 1, j}), vis[m - 1][j] = true;
        }

        // BFS se boundary ke 1s ka spread mark karo
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }

        // Andar bache hue 1s ko count karo jo visited nahi hue
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
