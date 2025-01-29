class Solution {
public:
    int usingRec(string &a, string &b,int i,int j){
        // base case will be written after one processing
        if(i>=a.length()) return 0;
        if(j>=b.length()) return 0;



        // one case to be solved
        int ans = 0;
        // if my both of the char are matching
        if(a[i]==b[j]){
            ans = 1 + usingRec(a,b,i+1,j+1);
        }
        else{
            ans = max(usingRec(a,b,i+1,j),usingRec(a,b,i,j+1));
        }

        return ans;
    }
    int usingDP(string &a, string &b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.length()) return 0;
        if(j>=b.length()) return 0;


        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // one case to be solved
        int ans = 0;
        // if my both of the char are matching
        if(a[i]==b[j]){
            ans = 1 + usingDP(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(usingDP(a,b,i+1,j,dp),usingDP(a,b,i,j+1,dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int usingTab(string a, string b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    // fill something into the dp according to the base cases 
    // here we took the size of the 2D matrix increasd because we need to attain indexes in tabulation
    // so to not get out of bound this is mandatory
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
        int ans = 0;
        // if my both of the char are matching
        if(a[i]==b[j]){
            ans = 1 + dp[i+1][j+1];
        }
        else{
            ans = 0 + max(dp[i+1][j],dp[i][j+1]);
        }
        dp[i][j] = ans;
        }


    }

    return dp[0][0];


    }
    int longestCommonSubsequence(string a, string b) {
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length(),-1));
        int ans = usingTab(a,b); return ans;
    }
};