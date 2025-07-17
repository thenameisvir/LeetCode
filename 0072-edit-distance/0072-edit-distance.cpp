class Solution {
public:
    int solve(string str1, string str2){
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][m] = n-i;
        }

        for(int i=0;i<=m;i++){
            dp[n][i] = m-i;
        }


        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                if(str1[i]==str2[j]){
                    dp[i][j] = dp[i+1][j+1];;
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
        return solve(word1,word2);
    }
};