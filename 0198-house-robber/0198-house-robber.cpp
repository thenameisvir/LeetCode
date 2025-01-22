class Solution {
public:
    int solveUsingMemo(vector<int>& arr,int index,vector<int>&dp){
        if(index>=arr.size()){
            return 0;
        }

        // dp ko process karlo na 

        if(dp[index]!=-1){
            return dp[index];
        }

        // ek case solve karo include exclude ka 
        int inc = arr[index] + solveUsingMemo(arr,index+2,dp);
        int exc = 0 + solveUsingMemo(arr,index+1,dp);

        dp[index] = max(inc,exc);

        return dp[index];
    }
    int rob(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        int ans2 = solveUsingMemo(arr,0,dp);
        return ans2;
    }
};