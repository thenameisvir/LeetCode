class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& used, vector<int>& ans, vector<vector<int>>& v) {
        if (ans.size() == nums.size()) {
            v.push_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; // Already used element ko skip karo
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue; // Duplicate check

            used[i] = true;
            ans.push_back(nums[i]);
            solve(nums, used, ans, v);
            ans.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());  // Sorting zaroori hai!
        solve(nums, used, ans, v);
        return v;
    }
};
