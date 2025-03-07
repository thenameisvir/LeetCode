class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string str = "";
        // carry universal rahegi aaj k baad bhulna mat
        int carry = 0;
        while(i>=0 || j>=0 || carry!=0){
            int a = 0, b = 0;
            if(i>=0){
                a = num1[i]-'0';
                i--;
            }
            if(j>=0){
                b = num2[j]-'0';
                j--;
            }

            // yaha tak maine elements nikal liye hai 
            int sum = a + b + carry;
            if(sum>=10){
                carry = sum/10;
            }
            else{
                carry = 0;
            }

            int ld = sum%10;
            // yaha maine carry ko bhi store kara liya hai ache se aur sb set hai
            str = char(ld+'0') + str;
        }

        if(str=="") str = "0";


        return str;
    }
};