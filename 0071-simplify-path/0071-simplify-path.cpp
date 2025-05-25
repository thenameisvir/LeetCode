class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int i = 0;
        while(i<path.size()){
            int start = i;
            int end = i+1;
            while(end<path.size() && path[end]!='/'){
                end++;
            }
            i = end;
            string temp = path.substr(start,end-start);
            if(temp=="/" || temp=="/."){
                continue;
            }
            else if(temp!="/.."){
                st.push(temp);
            }
            else if(!st.empty() && temp=="/.."){
                st.pop();
            }
        }

        string ans = "";
        if(st.empty()){
            ans.push_back('/');
            return ans;
        }

        while(!st.empty()){
            string p = st.top();
            ans = p + ans;
            st.pop();
        }

        return ans;
    }
};