class Solution {
public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        // base case baad me 
        if(i>=s1.size() && j<s2.size()){
            int sum = 0;
            while(j<s2.size()){
                sum+=int(s2[j]);
                j++;
                
            }
            return sum;
        }

        if(j>=s2.size() && i<s1.size()){
            int sum = 0;
            while(i<s1.size()){
                sum+=int(s1[i]);
               i++;
            }
             return sum;
        }

        if(i>=s1.size() && j>=s2.size()) return 0;


        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1,dp);
        }

        int op1 = int(s1[i]) + solve(s1,s2,i+1,j,dp);
        int op2 = int(s2[j]) + solve(s1,s2,i,j+1,dp);

        return dp[i][j] = min(op1,op2);
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size() + 1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,0,0,dp);
    }
};