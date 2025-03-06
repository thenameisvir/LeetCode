class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& arr) {
        vector<bool>vis(arr.size(),false);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        // initial state maintained
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto i:arr[top]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }

        for(int i=0;i<vis.size();i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};