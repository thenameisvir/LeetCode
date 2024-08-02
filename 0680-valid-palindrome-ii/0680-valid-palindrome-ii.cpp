class Solution {
public:
    bool check1(string str) {
        int s = 0;
        int e = str.length() - 1;
        int i = 0;
        while (s <= e) {
            if (str[s] != str[e]) {
                if (i == 0) {
                    s++;  // Skip the left character
                    i++;
                    continue;  // Check again with the same e
                } else {
                    return false;
                }
            }
            s++;
            e--;
        }
        return true;
    }

    bool check2(string str) {
        int s = 0;
        int e = str.length() - 1;
        int i = 0;
        while (s <= e) {
            if (str[s] != str[e]) {
                if (i == 0) {
                    e--;  // Skip the right character
                    i++;
                    continue;  // Check again with the same s
                } else {
                    return false;
                }
            }
            s++;
            e--;
        }
        return true;
    }

    bool validPalindrome(string str) {
        return check1(str) || check2(str);
    }
};
