class Solution {
public:
    int solve(string& str1, string& str2, int i, int j,vector<vector<int>>&dp) {
        if(i >= str1.size() && j >= str2.size()) return 0;
        if(i >= str1.size()) return str2.size() - j;
        if(j >= str2.size()) return str1.size() - i;


        if(dp[i][j]!=0){
            return dp[i][j];
        }


        if(str1[i] == str2[j]) {
            return solve(str1, str2, i+1, j+1,dp);
        }

        // If not equal, consider replace, insert, delete
        int replaceOp = 1 + solve(str1, str2, i+1, j+1,dp);
        int insertOp = 1 + solve(str1, str2, i, j+1,dp);
        int deleteOp = 1 + solve(str1, str2, i+1, j,dp);

        return dp[i][j] =  min(replaceOp, min(insertOp, deleteOp));
    }

    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m  = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        return solve(str1, str2, 0, 0,dp);
    }
};
