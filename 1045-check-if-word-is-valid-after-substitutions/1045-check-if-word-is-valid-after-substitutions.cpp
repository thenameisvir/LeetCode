class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(int i=0;i<str.size();i++){
            if(str[i]=='a'){
                st.push(str[i]);
            }
            else if(str[i]=='b'){
                st.push(str[i]);
            }
            else if(str[i]=='c' && st.size()>=2){
                char ch1 = st.top();st.pop();
                char ch2 = st.top();st.pop();
                if(ch1=='b' && ch2=='a'){
                    continue;
                }
                else{
                    st.push(ch2);
                    st.push(ch1);
                    st.push(str[i]);
                }
            }
            else if(str[i]=='c' && st.size()<2){
                st.push(str[i]);
            }
        }

        if(st.empty()) return true;

        return false;
    }
};