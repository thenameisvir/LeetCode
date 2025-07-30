class Solution {
public:
    bool check(vector<string>& arr, string &temp) {
        for (auto i : arr) {
            if (temp == i) {
                return true;
            }
        }
        return false;
    }

    void solve(string &s, vector<string>& arr, vector<string>& ans, string temp, int index) {
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        string str = "";
        for (int i = index; i < s.size(); i++) {
            str += s[i];

            if (check(arr, str)) {
                string newTemp = "";

                if (temp.empty()) {
                    newTemp = str;
                } else {
                    newTemp = temp + " " + str;
                }

                solve(s, arr, ans, newTemp, i + 1);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& arr) {
        vector<string> ans;
        string temp = "";
        solve(s, arr, ans, temp, 0);
        return ans;
    }
};
