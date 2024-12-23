class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch=='(' || st.empty()){
                st.push(ch);
            }
            else if(ch==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }


        return st.size();
    }
};