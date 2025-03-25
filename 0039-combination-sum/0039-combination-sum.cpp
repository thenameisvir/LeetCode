class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<vector<int>>& v, vector<int>& ans) {
        if (target == 0) {
            v.push_back(ans);
            return;
        }
        if (i >= candidates.size()) return;  // Bas yahi condition rakhni hai

        // ✅ INCLUDE the current element
        if (target >= candidates[i]) { // Yahan check karna chahiye, pehle hi return nahi
            ans.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, v, ans);
            ans.pop_back();
        }

        // ✅ EXCLUDE the current element
        solve(candidates, target, i + 1, v, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ans;
        solve(candidates, target, 0, v, ans);
        return v;
    }
};
