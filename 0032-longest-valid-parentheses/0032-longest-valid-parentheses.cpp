class Solution {
public:
    int longestValidParentheses(string str) {
        int left = 0, right = 0, maxLen = 0;

        // Left to Right
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                left++;
            } else {
                right++;
            }

            if(left == right) {
                maxLen = max(maxLen, 2 * right);
            }
            else if(right > left) {
                left = right = 0;
            }
        }

        // Right to Left
        left = right = 0;
        for(int i = str.length() - 1; i >= 0; i--) {
            if(str[i] == '(') {
                left++;
            } else {
                right++;
            }

            if(left == right) {
                maxLen = max(maxLen, 2 * left);
            }
            else if(left > right) {
                left = right = 0;
            }
        }

        return maxLen;
    }
};
