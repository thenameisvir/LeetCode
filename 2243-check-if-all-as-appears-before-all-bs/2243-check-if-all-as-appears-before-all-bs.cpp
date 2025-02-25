class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' && flag) continue;
            else if(s[i]=='b') flag = false;
            else if(s[i]=='a' && !flag) return false;
        }

        return true;
    }
};