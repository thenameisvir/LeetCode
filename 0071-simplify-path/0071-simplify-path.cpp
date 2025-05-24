class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.size();
        for(int i = 0; i < n; ) {
            // skip all '/'
            while(i < n && path[i] == '/') i++;

            // get the next component
            int start = i;
            while(i < n && path[i] != '/') i++;
            string part = path.substr(start, i - start);

            if(part == "" || part == ".") {
                // do nothing, skip
            } else if(part == "..") {
                if(!stack.empty()) stack.pop_back();
            } else {
                // normal directory name
                stack.push_back(part);
            }
        }

        // build result
        string ans = "/";
        for(int i = 0; i < stack.size(); i++) {
            ans += stack[i];
            if(i != stack.size() - 1) ans += "/";
        }

        return ans;
    }
};
