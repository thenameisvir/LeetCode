class Solution {
public:
    void dfs(int src,unordered_map<int,bool>&vis,vector<vector<int>>& isConnected,int n){
        vis[src] = true;

        // yaha adjacncy list nahi hai col me krna padega
        int col = n;
        int row = src;

        for(int i = 0;i<col;i++){
            if(isConnected[row][i]==1 && !vis[i]){
                dfs(i,vis,isConnected,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();
         unordered_map<int,bool>vis;
         int count = 0;
         for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,isConnected,n);
                count++;
            }
         }

         return count;
    }
};