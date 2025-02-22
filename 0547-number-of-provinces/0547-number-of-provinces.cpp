class Solution {
public:
    void dfs(int src,unordered_map<int,bool>&vis,vector<vector<int>>& arr,int n,unordered_map<int, list<int>> &adj){
        vis[src] = true;

        for(auto i:adj[src]){
            if(!vis[i]){
                dfs(i,vis,arr,n,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        // adjacency list banate hai bc 
        int n = arr.size();
        unordered_map<int, list<int>> adj;

for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
        if (arr[i][j] == 1 && i != j) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}
    int count = 0;
    unordered_map<int,bool>vis;
    for(int i=0;i<arr.size();i++){
        if(!vis[i]){
            dfs(i,vis,arr,n,adj);
        count++;
    }

    }

    return count;

    }
};