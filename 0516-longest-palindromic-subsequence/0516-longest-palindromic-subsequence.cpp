class Solution {
public:
    int space(string str1,string str2){
        int n = str1.size()-1;
        vector<int>prev(n+2,0);
        for(int i=n;i>=0;i--){
            vector<int>curr(n+2,0);
            for(int j=n;j>=0;j--){
                int ans = 0;
                if(str1[i]==str2[j]){
                    ans = 1 + prev[j+1];
                }
                int ans2 = prev[j];
                int ans3 = curr[j+1];

                curr[j] = max(ans,max(ans2,ans3));
            }

            prev = curr;
        }

        return prev[0];
    }
    int longestPalindromeSubseq(string s) {
        string str1 = s;
        reverse(s.begin(),s.end());
        string str2 = s;
        return space(str1,str2);
    }
};