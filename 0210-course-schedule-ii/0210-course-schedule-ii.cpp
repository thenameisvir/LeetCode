class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        unordered_map<int,list<int>>adj; // galti ki thi yaha list lagana bhula
        for(auto i:arr){
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
        }

        // yaha tak apan ne adjacency list bana li hai ekdum mst

        unordered_map<int,int>in;
        queue<int>q;
        vector<int>v;
        // indegree nikal li ache se
        for(auto i:adj){
            for(auto j:i.second){
                in[j]++;
            }
        }

        // ab 0 dependency wale ko push karo

        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        // ab apna logic;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            v.push_back(front);
            for(auto i:adj[front]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }

        if(v.size()==n){
            return v;
        }
        else{
            return {};
        }


    }
};