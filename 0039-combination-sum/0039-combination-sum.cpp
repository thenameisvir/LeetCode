class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& v, vector<int>& ans, int index) {
        if (target == 0) { // ✅ Base case: If target becomes 0, add to result
            v.push_back(ans);
            return;
        }
        if (index >= candidates.size() || target < 0) return; // ❌ If we go out of bounds or target is negative, return

        // ✅ INCLUDE the current element
        ans.push_back(candidates[index]); // Pick the element
        solve(candidates, target - candidates[index], v, ans, index); // Stay at the same index (pick again)
        ans.pop_back(); // Backtrack (Undo the choice)

        // ❌ EXCLUDE the current element
        solve(candidates, target, v, ans, index + 1); // Move to next index (skip current)
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ans;
        solve(candidates, target, v, ans, 0);
        return v;
    }
};
