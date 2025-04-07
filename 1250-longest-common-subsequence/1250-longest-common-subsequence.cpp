class Solution {
public:
    
    
    int tab(string s1, string s2){
        int i = s1.length();
        int j = s2.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));

        for(int m = i-1;m>=0;m--){
            for(int n = j-1;n>=0;n--){
                
        int ans = 0;
        if(s1[m]==s2[n]){
            
            ans = 1 + dp[m+1][n+1];
        }
        else{
            // ek case tera ek case mera
            ans = 0 + max(dp[m+1][n],dp[m][n+1]);
            
        }

        dp[m][n] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string &s1, string &s2) {
        int i = s1.length();
        int j = s2.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));
        return tab(s1,s2);
        
    }
};