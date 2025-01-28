class Solution {
public:
    int usingRec(string text1, string text2,int i,int j){
        // base case toh lund smjh na aaye 
        if(i>=text1.length()){
            return 0;
        }
        if(j>=text2.length()){
            return 0;
        }

        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1+ usingRec(text1,text2,i+1,j+1); // ye sb baad me dekhenge
        }
        else{
            ans = max(usingRec(text1,text2,i+1,j),usingRec(text1,text2,i,j+1));
        }

        return ans;

    }
    int usingMemo(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
        if(i>=text1.length()){
            return 0;
        }
        if(j>=text2.length()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1+ usingMemo(text1,text2,i+1,j+1,dp); // ye sb baad me dekhenge
        }
        else{
            ans = max(usingMemo(text1,text2,i+1,j,dp),usingMemo(text1,text2,i,j+1,dp));
        }

        dp[i][j] = ans;

        return dp[i][j];



    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size(),-1));
        int ans = usingMemo(text1,text2,i,j,dp);
        return ans;


    }
};