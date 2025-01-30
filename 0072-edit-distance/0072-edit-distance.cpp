class Solution {
public:
    int usingMemo(string word1, string word2,int i,int j,vector<vector<int>>&dp){
        // base case would be the same as the recursion
        if(i>=word1.length()){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }


        // store into the dp array
        if(dp[i][j]!=0){
            return dp[i][j];
        }

        int ans = 0;

        if(word1[i]==word2[j]){
            ans = 0 + usingMemo(word1,word2,i+1,j+1,dp);
        }
        else{
            int replace = 1 + usingMemo(word1,word2,i+1,j+1,dp);
            int insert = 1 + usingMemo(word1,word2,i+1,j,dp);
            int remove = 1 + usingMemo(word1,word2,i,j+1,dp);

            ans = min(replace,min(insert,remove));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,0));
        int ans = usingMemo(word1,word2,0,0,dp);
        return ans;
    }
};