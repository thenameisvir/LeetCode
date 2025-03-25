class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<vector<int>>&v,vector<int>ans,int index){
        if(target==0){
            v.push_back(ans);
            return;
        }
        if(target<0) return;

        // base case dekhenge abhi baad me

        for(int i=index;i<candidates.size();i++){
            if(target>=candidates[i]){
                ans.push_back(candidates[i]);
                solve(candidates,target-candidates[i],v,ans,i);
                ans.pop_back();
            }


            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>ans;
        solve(candidates,target,v,ans,0);

        return v;
    }
};