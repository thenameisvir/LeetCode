class Solution {
public:
    int solve(string word1,string word2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i>=n && j<m){
            return m-j;
        }
        if(j>=m && i<n){
            return n-i;
        }
        if(i>=n && j>=m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return solve(word1,word2,n,m,i+1,j+1,dp);
        }
        
        int op1 = 1 + solve(word1,word2,n,m,i+1,j,dp);
        int op2 = 1 + solve(word1,word2,n,m,i,j+1,dp);

        return dp[i][j] = min(op1,op2);

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(word1,word2,n,m,0,0,dp);
    }
};