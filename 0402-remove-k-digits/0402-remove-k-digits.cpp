class Solution {
public:
    string removeKdigits(string str, int k) {
        vector<int> v;
        for (int i = 0; i < str.size(); i++) {
            v.push_back(str[i] - '0');
        }

        stack<int> st;
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() && k > 0 && v[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(v[i]);
        }

        // Agar k abhi bhi bacha ho
        while (k-- > 0 && !st.empty()) {
            st.pop();
        }

        // Stack to vector (ulta aata hai)
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Leading zeros remove karo
        int i = 0;
        while (i < ans.size() && ans[i] == 0) {
            i++;
        }

        string res = "";
        for (int j = i; j < ans.size(); j++) {
            res += (ans[j] + '0');
        }

        return res == "" ? "0" : res;
    }
};
