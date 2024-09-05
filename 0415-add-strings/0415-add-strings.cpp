class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;

        // Loop through both strings from the end to the beginning
        while (p1 >= 0 || p2 >= 0 || carry != 0) {
            int n1 = 0, n2 = 0;
            
            // Get digit from num1 if available
            if (p1 >= 0) {
                n1 = num1[p1] - '0';
                p1--;
            }
            
            // Get digit from num2 if available
            if (p2 >= 0) {
                n2 = num2[p2] - '0';
                p2--;
            }

            // Calculate sum of digits and carry
            int csum = n1 + n2 + carry;
            int digit = csum % 10;
            carry = csum / 10;

            // Add the digit to the result
            ans.push_back(digit + '0');
        }

        // Since digits were added in reverse order, reverse the result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
