class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> ans(n, 0);
        ans[n - 1] = nums[n - 1];
        ans[n - 2] = max(nums[n - 2], nums[n - 1]);

        for(int i = n - 3; i >= 0; i--) {
            ans[i] = max(nums[i] + ans[i + 2], ans[i + 1]);
        }

        return ans[0];
    }
};
