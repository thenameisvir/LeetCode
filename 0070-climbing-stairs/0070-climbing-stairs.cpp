class Solution {
public:
    int climb(int n,int a,int b,int c,int i){
        if(i>=n) return c;

        c = a+b;
        a = b;
        b = c;
        return climb(n,a,b,c,i+1);
    }
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int i = 0;
        int c;
        return climb(n,a,b,c,i);
    }
};