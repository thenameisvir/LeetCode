class Solution {
public:
    int solve(string &str1, string &str2,int i,int j,vector<vector<int>>&dp){
        if(i>=str1.size() || j>=str2.size()) {
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans1 = 0;
        if(str1[i]==str2[j]){
            ans1 = 1 + solve(str1,str2,i+1,j+1,dp); 
        }
        int ans2 = 0 + solve(str1,str2,i,j+1,dp);
        int ans3 = 0 + solve(str1,str2,i+1,j,dp);

        return dp[i][j] = max(ans1,max(ans2,ans3));

    }
    int longestCommonSubsequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        int i = 0;
        int j = 0;
        return solve(str1,str2,i,j,dp);
    }
};