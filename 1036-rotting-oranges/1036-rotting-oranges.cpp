class Solution {
public:
    bool isOkay(vector<vector<int>>& nums, int x, int y, map<pair<int,int>,bool>& vis) {
        int n = nums.size();
        int m = nums[0].size();
        if(x >= 0 && x < n && y >= 0 && y < m && nums[x][y] == 1 && !vis[{x, y}]) {
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& nums, queue<pair<int,int>>& q, map<pair<int,int>,bool>& vis) {
        int count = 0;
        while(!q.empty()) {
            int sz = q.size();  // snapshot of current level size
            for(int i = 0; i < sz; i++) {
                auto front = q.front(); q.pop();
                int tempx = front.first;
                int tempy = front.second;

                int dx[] = {0, 1, -1, 0};
                int dy[] = {1, 0, 0, -1};

                for(int k = 0; k < 4; k++) {
                    int newx = tempx + dx[k];
                    int newy = tempy + dy[k];
                    if(isOkay(nums, newx, newy, vis)) {
                        nums[newx][newy] = 2;
                        vis[{newx, newy}] = true;
                        q.push({newx, newy});
                    }
                }
            }
            count++;
        }
        return count - 1;
    }

    int orangesRotting(vector<vector<int>>& nums) {
        map<pair<int,int>,bool> vis;
        queue<pair<int,int>> q;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                if(nums[i][j] == 2) {
                    q.push({i, j});
                    vis[{i, j}] = true;
                }
            }
        }

        int ans = solve(nums, q, vis);

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                if(nums[i][j] == 1) {
                    return -1; // fresh orange still left
                }
            }
        }

        return ans < 0 ? 0 : ans; // edge case: no fresh or rotten oranges initially
    }
};
