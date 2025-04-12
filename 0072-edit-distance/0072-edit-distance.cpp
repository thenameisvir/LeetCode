class Solution {
public:
    int check(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i>=word1.length() && j>=word2.length()) return 0;
        if(i>=word1.length() && j<word2.length()) return word2.length()-j;
        if(j>=word2.length() && i<word1.length()) return word1.length()-i;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // main case
        int ans = 0;
        if(word1[i]==word2[j]){
            dp[i][j] = 0 + check(word1,word2,i+1,j+1,dp);
        }
        else{
            int op1 = 1 + check(word1,word2,i+1,j+1,dp);
            int op2 = 1 + check(word1,word2,i,j+1,dp);
            int op3 = 1 + check(word1,word2,i+1,j,dp);

            dp[i][j] = min(op1,min(op2,op3));
        }

        return dp[i][j];

    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length() + 1, vector<int>(word2.length()+1,-1));
        return check(word1,word2,0,0,dp);
    }
};