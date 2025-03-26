class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&v,vector<int>&ans,int index){
        // base case baad me likhenge
        if(index>=nums.size()){
            v.push_back(nums);
            return;
        }

        // ek case solve karte hai 
        unordered_map<int,bool>vis;
        for(int i=index;i<nums.size();i++){
            // pehle toh swap kardo 
            if(vis.find(nums[i])!=vis.end()){
                continue;
            }
            vis[nums[i]]=true;
            if(i>index && nums[i]==nums[i-1]) continue;
            swap(nums[i],nums[index]);
            solve(nums,v,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        solve(nums,v,ans,0);
        return v;
    }
};