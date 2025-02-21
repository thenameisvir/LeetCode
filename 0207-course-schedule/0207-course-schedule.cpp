class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        
        unordered_map<int,list<int>>adj;
        for(vector<int> i:arr){
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
        }

        // yaha se start hota hai mani Kahn's algo
        unordered_map<int,int>in;
        queue<int>q;
        vector<int>v;
        // indegree nikal li apan ne
        for(auto i:adj){
            for(auto j:i.second){
                in[j]++;
            }
        }

        // ab jis jiski indegree 0 hai usko push kardo queue me
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        // ab chalte hai apne main logic pr 
        while(!q.empty()){
            int front = q.front();
            q.pop();
            v.push_back(1);
            for(auto i:adj[front]){
                
                    in[i]--;
                    if(in[i]==0) q.push(i);
                
            }
        }


        return v.size()==adj.size();

        



    }
};