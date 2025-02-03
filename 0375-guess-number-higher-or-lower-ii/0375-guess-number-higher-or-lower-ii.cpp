class Solution {
public:
    int usingRec(int s,int e){
        // base case 
        if(s>=e) return 0; // range se bahar 0 penalty // ek hi number hai firse 0 penalty

        int ans = INT_MAX;
        for(int i=s;i<=e;i++){
            ans = min(ans, i+ max(usingRec(s,i-1),usingRec(i+1,e)));
        }

        return ans;

    }
    int usingMemo(int s,int e,vector<vector<int>>&dp){
        // base case rhega is case me ki 
        if(s>=e) return 0;

        // store in dp now 
        if(dp[s][e]!=-1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i=s;i<=e;i++){
            ans = min(ans, i+ max(usingMemo(s,i-1,dp),usingMemo(i+1,e,dp)));
        }

        dp[s][e] = ans;
        return dp[s][e];

    }
    int getMoneyAmount(int n) {
        int s = 1;
        int e = n;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = usingMemo(s,e,dp);
        return ans;
    }
};