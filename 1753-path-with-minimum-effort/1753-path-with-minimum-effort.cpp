#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        // {effort, {x, y}} -> Start from (0,0)
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // Directions: Up, Right, Down, Left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            // If we reached the destination, return the effort
            if (x == row - 1 && y == col - 1) return effort;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return -1; // This case should never occur
    }
};
