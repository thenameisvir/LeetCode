class Solution {
public:
    void solve(vector<int>& nums,vector<int>&ans,vector<vector<int>>&v,int j){
        if(j==nums.size()-1){
            v.push_back(nums);
            return;
        }

        // varna toh ye kardo
        for(int i=j;i<nums.size();i++){
            swap(nums[i],nums[j]);
            solve(nums,ans,v,j+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>ans;

        solve(nums,ans,v,0);

        return v;
    }
};