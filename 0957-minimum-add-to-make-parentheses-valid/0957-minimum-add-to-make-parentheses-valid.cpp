class Solution {
public:
    int minAddToMakeValid(string s) {
       std::stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        char curr = s[i];
        if(st.empty() || curr == '(') {
            st.push(curr);
        }
        else if(curr == ')') {
            if(st.top() == '(') {
                st.pop();
            } else {
                st.push(curr);
            }
        }
    }

    return st.size();
    }

};