class Solution {
public:
    void solve(vector<int>& arr, int t, int start, vector<int>& ans, vector<vector<int>>& v) {
        if (t == 0) {
            v.push_back(ans);
            return;
        }

        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i] == arr[i - 1]) continue; // ✅ Duplicate elements ko skip kar diya

            if (arr[i] > t) break; // ✅ Optimization: Agar number target se bada hai toh aage check mat karo

            ans.push_back(arr[i]);
            solve(arr, t - arr[i], i + 1, ans, v); // ✅ i+1 kar diya, kyunki ek element ek baar hi use karna hai
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        sort(arr.begin(), arr.end());  // ✅ Sorting zaroori hai
        vector<vector<int>> v;
        vector<int> ans;
        solve(arr, t, 0, ans, v);
        return v;
    }
};
