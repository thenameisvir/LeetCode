class Solution {
public:
    void solve(vector<string>& v, int oCount, int cCount, string output) {
        if (oCount == 0 && cCount == 0) {
            v.push_back(output);
            return;
        }
        if (oCount > 0) {
            solve(v, oCount - 1, cCount, output + '(');
        }
        if (cCount > oCount) {
            solve(v, oCount, cCount - 1, output + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(v, n, n, "");
        return v;
    }
};
