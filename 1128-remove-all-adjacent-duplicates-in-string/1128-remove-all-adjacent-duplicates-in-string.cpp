class Solution {
public:
    string removeDuplicates(string s) {
        string str = "";
        for(int i=0;i<s.length();i++){
            if(!str.empty() && str[str.length()-1]==s[i]){
                str.pop_back();
            }
            else{
                str.push_back(s[i]);
            }
        }

        return str;
    }
};