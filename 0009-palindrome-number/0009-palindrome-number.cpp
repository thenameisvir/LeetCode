class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long o = x;
        long sum = 0;
        while(o!=0){
            int a = o%10;
            sum = (sum*10)+a;
            o/=10;
        }
        if(sum==x){
            return true;
        }
        else{
            return false;
        }

    }
};