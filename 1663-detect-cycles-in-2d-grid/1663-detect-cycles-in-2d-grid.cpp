class Solution {
public:
    bool isOkay(vector<vector<char>>& nums, int x, int y, int xx, int yy, map<pair<int, int>, bool>& vis) {
        int n = nums.size();
        int m = nums[0].size();
        if (x >= 0 && x < n && y >= 0 && y < m && nums[xx][yy] == nums[x][y] && !vis[{x, y}]) {
            return true;
        }
        return false;
    }

    bool solve(vector<vector<char>>& nums, int xx, int yy, map<pair<int, int>, bool>& vis) {
        queue<pair<pair<int, int>, pair<int, int>>> q;  // {{curr_x, curr_y}, {parent_x, parent_y}}
        q.push({{xx, yy}, {-1, -1}});
        vis[{xx, yy}] = true;

        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            int x = front.first.first;
            int y = front.first.second;
            int px = front.second.first;
            int py = front.second.second;

            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx == px && newy == py) continue; // ignore parent

                if (newx >= 0 && newx < nums.size() && newy >= 0 && newy < nums[0].size()
                    && nums[newx][newy] == nums[x][y]) {

                    if (vis[{newx, newy}]) {
                        return true; // visited and not parent → cycle
                    }

                    vis[{newx, newy}] = true;
                    q.push({{newx, newy}, {x, y}});
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& nums) {
        map<pair<int, int>, bool> vis;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (!vis[{i, j}]) {
                    if (solve(nums, i, j, vis)) return true;
                }
            }
        }

        return false;
    }
};
