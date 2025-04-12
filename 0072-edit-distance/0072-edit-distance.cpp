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
    int tab(string word1, string word2){
    vector<vector<int>>dp(word1.length() + 1, vector<int>(word2.length()+1,-1));
    
    for(int j = 0; j <= word2.length(); j++) {
    dp[word1.length()][j] = word2.length() - j;
}
for(int i = 0; i <= word1.length(); i++) {
    dp[i][word2.length()] = word1.length() - i;
}

    
    for(int i = word1.length()-1;i>=0;i--){
        for(int j = word2.length()-1;j>=0;j--){
            int ans = 0;
        if(word1[i]==word2[j]){
            dp[i][j] = 0 + dp[i+1][j+1];
        }
        else{
            int op1 = 1 + dp[i+1][j+1];
            int op2 = 1 + dp[i][j+1];
            int op3 = 1 + dp[i+1][j];

            dp[i][j] = min(op1,min(op2,op3));
        }

        
        }
    }

    return dp[0][0];


    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length() + 1, vector<int>(word2.length()+1,-1));
        return tab(word1,word2);
    }
};