class Solution {
public:
    int Memo(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
        // base case baad me dekhenge 
        if(i>=word1.length()){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }
        // check if it is present in the dp array
        if(dp[i][j]!=0){
            return dp[i][j];
        }

        // now put the recursion
        int ans = 0;
        if(word1[i]==word2[j]){
            ans = 0 + Memo(word1,word2,i+1,j+1,dp);
        }
        else{
            // now in the edit game we will do 3 cases to make it correct 
            int replace = 1 + Memo(word1,word2,i+1,j+1,dp);
            // here in replace we did i+1,j+1 becaue we are almost making it 
            int insert = 1 + Memo(word1,word2,i+1,j,dp);
            // here we inserted to the word1 and making it matchable
            int remove = 1 + Memo(word1,word2,i,j+1,dp);

            ans = min(replace,min(insert,remove));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    // int Tab(){

    // }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,0));
        int ans = Memo(word1,word2,0,0,dp);
        return ans;
    }
};