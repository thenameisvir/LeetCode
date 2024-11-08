class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
             char ch = s[i];

             st.push(ch);

             while(st.size()>=3){
                char c = st.top(); st.pop();
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();

                if(c=='c' && b=='b' && a=='a'){
                    continue;
                }
                else{
                    st.push(a);
                    st.push(b);
                    st.push(c);
                    break;
                }
             }
        }

        return st.empty();
    }
};