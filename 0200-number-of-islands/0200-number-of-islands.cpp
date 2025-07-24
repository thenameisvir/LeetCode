class Solution {
public:
    bool isOkay(vector<vector<char>>& nums,map<pair<int,int>,bool>&vis,int x,int y){
        if(x>=0 && y>=0 && x<nums.size() && y<nums[x].size() && !vis[{x,y}] && nums[x][y]=='1'){
            return true;
        }

        return false;
    }
    void solve(int i,int j,map<pair<int,int>,bool>&vis,vector<vector<char>>& nums){

        vis[{i,j}] = true;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            auto front = q.front(); q.pop();
            int tempx = front.first;
            int tempy = front.second;

            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0};

            for(int i=0;i<4;i++){
                int newx = tempx + dx[i];
                int newy = tempy + dy[i];

                if(isOkay(nums,vis,newx,newy)){
                    vis[{newx,newy}] = true;
                    q.push({newx,newy});
                }


            }
        }


    }
    int numIslands(vector<vector<char>>& nums) {
        map<pair<int,int>,bool>vis;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(!vis[{i,j}] && nums[i][j]=='1'){
                    solve(i,j,vis,nums);
                    count++;
                }
            }
        }

        return count;
    }
};