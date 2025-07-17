class Solution {
public:
    int tab(string str1, string str2,int n,int m){

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // base case k according filliong kardo array ki 
        for(int i=0;i<=n;i++){
            dp[i][m] = n-i;
        }

        for(int i=0;i<=m;i++){
            dp[n][i] = m-i;
        }

        // base case k hisab se sab insert kar dia hai humne 

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(str1[i]==str2[j]){
                    dp[i][j] = dp[i+1][j+1]; // yaha par 0 sirf 1 hi jagah p hai
                }
                else{
                    int ans1 = 1 + dp[i+1][j+1];
                    int ans2 = 1 + dp[i+1][j];
                    int ans3 = 1 + dp[i][j+1];

                    dp[i][j] = min({ans1,ans2,ans3});
                }
            }
        }

        return dp[0][0];


    }

    int space(string str1, string str2,int n,int m){
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        // int count = m;
        for(int i=0;i<=m;i++){
            prev[i] = m-i;
            
        }

        // curr[m] = 1;

        for(int i=n-1;i>=0;i--){
            curr[m] = n-i;
            for(int j=m-1;j>=0;j--){
                if(str1[i]==str2[j]){
                    curr[j] = prev[j+1];
                }
                else{
                    int ans1 = 1 + prev[j+1];
                    int ans2 = 1 + prev[j];
                    int ans3 = 1 + curr[j+1];

                    curr[j] = min({ans1,ans2,ans3});
                }
            }

            prev = curr;
        }

        return prev[0];

    }
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        return space(str1,str2,n,m);
    }
};