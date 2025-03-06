class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& arr) {
        vector<bool>vis(arr.size(),false);
        queue<int>q;
        q.push(0);
        vis[0] = true;

        // initial processing ho chuki hai 
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto i:arr[front]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }

        for(auto i:vis){
            if(!i) return false;
        }

        return true;
    }
};