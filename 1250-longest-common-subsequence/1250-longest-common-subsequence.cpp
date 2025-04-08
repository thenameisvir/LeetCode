class Solution {
public:
    int count = 0;
    void solve(string s1, string s2,int i,int j, int cnt){
        // base case
        if(i>=s1.length() || j>=s2.length()) {
            count = max(count , cnt);
            return;
        }
        // main case

        if(s1[i]==s2[j]){
            // cont+=1;
            solve(s1,s2,i+1,j+1, cnt + 1);
        }
        else{
            solve(s1,s2,i,j+1, cnt);
            solve(s1,s2,i+1,j , cnt);
        }

    }
    int longestCommonSubsequence(string s1, string s2) {
        int cnt = 0;
        solve(s1,s2,0,0, cnt);
        return count;
    }
};