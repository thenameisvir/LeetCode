class Solution {
public:
    bool isSafe(int x,int y,map<pair<int,int>,bool>&vis,vector<vector<char>>& arr){
        if(x>=0 && x<arr.size() && y>=0 && y<arr[0].size() && !vis[{x,y}] && arr[x][y]=='1'){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(int srcx, int srcy,map<pair<int,int>,bool>&vis,vector<vector<char>>& arr){
        // yaha ayega main logic ab tak apan ne original calls kar di hai
        // yaha par mai initial state maintain krne ki sochunga
        queue<pair<int,int>>q;
        q.push({srcx,srcy});
        vis[{srcx,srcy}] = true;
        // yaha tak apan logo ne inital state maintain karli hai ab kaam shuru karte hai
        while(!q.empty()){
            auto frontPair = q.front();
            int tempx = frontPair.first;
            int tempy = frontPair.second;
            q.pop();

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            // yaha par yaad rakhne wali cheese ye hai ki loop 4 tak chalayenge kyuki 4 
            // conditions hi toh check karni hai 
            for(int i=0;i<4;i++){
                int newX = tempx + dx[i];
                int newY = tempy + dy[i];

                if(isSafe(newX,newY,vis,arr)){
                    // toh apna kaam kardo chup chaap
                    vis[{newX,newY}] = true;
                    q.push({newX,newY});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& arr) {
        int count = 0; // yahi toh return karna hai mujhe after all
        map<pair<int,int>,bool>vis; // isme mere indexes ayenge aur true mark karna hoga
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                // yaha ayega thoda bhot logic check
                if(!vis[{i,j}] && arr[i][j]=='1'){
                    bfs(i,j,vis,arr);
                    count++;
                }
            }
        }


        return count;


    }
};