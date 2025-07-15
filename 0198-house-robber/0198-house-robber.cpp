class Solution {
public:
    int usingRec(vector<int>& arr,int i,vector<int>&dp){
        if(i>=arr.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int inc = arr[i] + usingRec(arr,i+2,dp);
        int exc = 0 + usingRec(arr,i+1,dp);

        return dp[i] = max(inc,exc);

    }
    int rob(vector<int>& arr) {
        vector<int>dp(arr.size()+1,-1);
        return usingRec(arr,0,dp);
    }
};