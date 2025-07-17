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
    int tab(string str1, string str2){
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));

    int n = str1.size()-1;
    int m = str2.size()-1;

    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){

            int ans1 = 0;
            if(str1[i]==str2[j]){
                ans1 = 1 + dp[i+1][j+1]; 
            }
            int ans2 = 0 + dp[i][j+1];
            int ans3 = 0 + dp[i+1][j];

            dp[i][j] = max(ans1,max(ans2,ans3));
        }
    }

    return dp[0][0];

    }

    int space(string str1, string str2){
        vector<int>prev(str2.size()+1,0);
        int n = str1.size()-1;
        int m = str2.size()-1;
        for(int i=n;i>=0;i--){
            vector<int>curr(m+2,0);
            for(int j=m;j>=0;j--){
                int ans1 = 0;
                if(str1[i]==str2[j]){
                    ans1 = 1 + prev[j+1];
                }
                int ans2 = curr[j+1];
                int ans3 = prev[j];

                curr[j] = max(ans1,max(ans2,ans3));
            }
            prev = curr;
        }

        return prev[0];

    }
    int longestCommonSubsequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        int i = 0;
        int j = 0;
        return space(str1,str2);
    }
};