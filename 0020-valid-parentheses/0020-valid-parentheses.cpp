class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i = 0;
        while(i<s.size()){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()=='{' && s[i]=='}' || st.top()=='[' && s[i]==']' || st.top()=='(' && s[i]==')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }

        if(st.empty()) return true;

        return false;
    }
};