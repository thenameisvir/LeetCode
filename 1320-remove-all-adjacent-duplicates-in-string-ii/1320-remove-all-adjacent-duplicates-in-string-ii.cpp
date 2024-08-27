class Solution {
public:
    bool kminusone(char& ch, string& ans, int k_1) {
        int it = ans.length() - 1;
        for (int i = 0; i < k_1; i++) {
            if (ans[it] != ch) return false;
            it--;
        }
        return true;
    }

    string removeDuplicates(string s, int k) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            char& ch = s[i];
            ans.push_back(ch);
            if (ans.length() >= k && kminusone(ch, ans, k - 1)) {
                for (int j = 0; j < k; j++) {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};
