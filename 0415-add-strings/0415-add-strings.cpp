class Solution {
public:

    void addRe(string &num1, string &num2, int p1, int p2, int carry, string &ans) {
        // base case
        if (p1 < 0 && p2 < 0) {
            if (carry != 0) {
                ans.push_back(carry + '0');
            }
            return;
        }

        // Solve one case
        int n1 = 0, n2 = 0;
        if (p1 >= 0) {
            n1 = num1[p1] - '0';
        }
        if (p2 >= 0) {
            n2 = num2[p2] - '0';
        }

        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum / 10;
        ans.push_back(digit + '0');

        // Recursive call
        addRe(num1, num2, p1 - 1, p2 - 1, carry, ans);
    }

    string addStrings(string num1, string num2) {
        string ans = "";
        addRe(num1, num2, num1.size() - 1, num2.size() - 1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

};
