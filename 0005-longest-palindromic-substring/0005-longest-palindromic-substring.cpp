class Solution {
public:
    bool is_palindrome(string&s,int start,int end){
        
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(is_palindrome(s,i,j)){
                    string t = s.substr(i,j-i+1);
                    if(t.size()>ans.size()){
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};