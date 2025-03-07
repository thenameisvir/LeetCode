class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry > 0) {  
            int a = 0, b = 0;

            if (i >= 0) {  
                a = num1[i] - '0';
                i--;
            } 

            if (j >= 0) {  
                b = num2[j] - '0';
                j--;
            }

            int sum = a + b + carry;  
            
            if (sum >= 10) {  
                carry = sum / 10;  
            } else {  
                carry = 0;  
            }

            int last_digit = sum % 10;
            result = char(last_digit + '0') + result;  
        }

        return result;
    }
};
