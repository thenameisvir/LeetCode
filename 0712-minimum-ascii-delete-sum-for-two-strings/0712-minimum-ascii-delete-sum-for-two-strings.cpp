class Solution {
public:
    vector<vector<int>> dp;
    
    int makichu(string &s1, string &s2, int i, int j) {
        if (i >= s1.length()) {
            int sum = 0;
            while (j < s2.length()) sum += s2[j++];
            return sum;
        }
        if (j >= s2.length()) {
            int sum = 0;
            while (i < s1.length()) sum += s1[i++];
            return sum;
        }
        if (dp[i][j] != -1) return dp[i][j]; // DP check

        if (s1[i] == s2[j]) {
            return dp[i][j] = makichu(s1, s2, i + 1, j + 1);
        } else {
            int option1 = s1[i] + makichu(s1, s2, i + 1, j);
            int option2 = s2[j] + makichu(s1, s2, i, j + 1);
            return dp[i][j] = min(option1, option2);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.length(), vector<int>(s2.length(), -1));
        return makichu(s1, s2, 0, 0);
    }
};
