class Solution {
public:
    bool check(vector<int>&curr,vector<int>&prev){
        if(prev[0]<=curr[0] && prev[1]<=curr[1] && prev[2]<=curr[2]){
            return true;
        }

        return false;
    }
    int tab(vector<vector<int>>& nums){
        int n = nums.size();
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int inc = 0;
            if(j==-1 || check(nums[i],nums[j])){
                inc = nums[i][2] + prev[i+1];
            }
            int exc = 0 + prev[j+1];

             curr[j+1] =  max(inc,exc);
            }
            prev = curr;
        }

    return curr[0];

    }
    int maxHeight(vector<vector<int>>& nums) {
        for(auto &i:nums){
            sort(i.begin(),i.end());
        }

        sort(nums.begin(),nums.end());

        int ans = tab(nums);
        return ans;
    }
};