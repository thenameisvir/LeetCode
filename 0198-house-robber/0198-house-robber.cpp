class Solution {
public:
    int usingRec(vector<int>& arr,int n){
        if(n>=arr.size()){
            return 0;
        }
        // base case was easy let;s do the processing
        int inc = arr[n] + usingRec(arr,n+2);
        int exc = 0 + usingRec(arr,n+1);

        // this is based on include exclude principle

        // now here we return the max value which will go upon the recursive tree

        return max(inc,exc);


    }
    int usingDp(vector<int>& arr,int n,vector<int>&dp){
        if(n>=arr.size()){
            return 0;
        }

        // idhar dp me store karenge
        if(dp[n]!=-1){
            return dp[n];
        }


        // idhar khudka process karo
        int inc = arr[n] + usingDp(arr,n+2,dp);
        int exc = 0 + usingDp(arr,n+1,dp);

        dp[n] = max(inc,exc);
        return dp[n];
    }
    int rob(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        int ans = usingDp(arr,0,dp);
        return ans;
        
    }
};