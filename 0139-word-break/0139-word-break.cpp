class Solution {
public:
    bool check(string &str,vector<string>&arr){
        for(auto i:arr){
            if(str==i){
                return true;
            }
        }

        return false;
    }
    bool solve(string&s, vector<string>& arr, int index,vector<int>&dp){
        if(index==s.size()){
            return true;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        string str = "";
        bool flag = false;

        for(int i=index;i<s.size();i++){
            str+=s[i];

            if(check(str,arr)){
                flag = flag || solve(s,arr,i+1,dp);
            }
        }

        return dp[index] =  flag;
    }
    bool tab(string s, vector<string>& arr){
        vector<int>dp(s.size()+1,-1);
        dp[s.size()] = 1;
        int n = s.size();
        for(int i = n-1;i>=0;i--)
        {
        string str = "";
        bool flag = false;

        for(int j=i;j<s.size();j++){
            str+=s[j];

            if(check(str,arr)){
                flag = flag || dp[j+1];
            }
        }

         dp[i] =  flag;
        }

        return dp[0];
    }
    bool wordBreak(string s, vector<string>& arr) {
        vector<int>dp(s.size()+1,-1);
        return tab(s,arr);
    }
};