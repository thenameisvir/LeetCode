class Solution {
public:
    void solve(int i,int j,string &str,int carry,string num1, string num2){
        if(i<0 && j<0 && carry==0){
            return;
        }
        int a = 0,b = 0;

        // ek case solve kardo 
        if(i>=0){
            a = num1[i] -'0';
            i--;
        }
        if(j>=0){
            b = num2[j] - '0';
            j--;
        }

        int sum = a + b + carry;
        if(sum>=10){
            carry = sum/10;
        }
        else{
            carry = 0;
        }

        int ld = sum%10;

        str = char(ld+'0') + str;
        solve(i,j,str,carry,num1,num2);

    }
    string addStrings(string num1, string num2) {
        int i = num1.length()-1;
        int j = num2.length()-1;
        string str = "";
        int carry = 0;
        solve(i,j,str,carry,num1,num2);
        if(str=="") str="0";


        return str;
    }
};