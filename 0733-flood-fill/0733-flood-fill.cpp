class Solution {
public:
    bool isSafe(int x,int y,map<pair<int,int>,bool> &vis,vector<vector<int>>& image,int original){
        // yaha apne edge cases likho 

        if(x>=0 && x<image.size() && y>=0 && y<image[0].size() && !vis[{x,y}] && image[x][y]==original){
            return true;
        }
        return false;


    }
    void solvebfs(int sr,int sc,int color,vector<vector<int>>& image,map<pair<int,int>,bool> &vis,int original){
        queue<pair<int,int>>q;
        // initial state maintain karenge
        vis[{sr,sc}] = true;
        q.push({sr,sc});
        image[sr][sc] = color;

        // yaha tak mera ek case solve ho chuka hai baki bfs kar dega 
        while(!q.empty()){
            auto toppair = q.front();
            q.pop();
            int tempx = toppair.first;
            int tempy = toppair.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            // yaha pr bhul gaya tha yaad rkhunga sada soniye
            for(int i=0;i<4;i++){
                int newx = tempx + dx[i];
                int newy = tempy + dy[i];
                if(isSafe(newx,newy,vis,image,original)){
                    image[newx][newy] = color;
                    q.push({newx,newy});
                    vis[{newx,newy}] = true;
                }
            }
        }



    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr,int sc, int color) {
        map<pair<int,int>,bool>vis; // ye mai rata nahi hu samajh ke kr raha hu 
        int original = image[sr][sc];
        solvebfs(sr,sc,color,image,vis,original);
        return image;
    }
};