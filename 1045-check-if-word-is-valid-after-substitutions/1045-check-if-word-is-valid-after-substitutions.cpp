class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            char ch = s[i];

            st.push(ch);

            while(st.size() >= 3) {
                char c = st.top(); st.pop();
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();

                if (a == 'a' && b == 'b' && c == 'c') {
                    // "abc" found, do not push them back
                    continue;
                } else {
                    // If it's not "abc", push them back in original order
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