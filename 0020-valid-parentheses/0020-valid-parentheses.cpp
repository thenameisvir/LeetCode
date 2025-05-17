class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        for(int i=0;i<s.size();i++){
            // char ch = st.top();
            if(st.empty() || s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')' && st.top()=='(' || s[i]=='}' && st.top()=='{' || s[i]==']' && st.top()=='[')
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        if(st.empty()) return true;


        return false;
    }
};