class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1;
        int i = 2;
        while (i <= n) {
            int c = a + b;
            a = b;
            b = c;
            i++;
        }
        return b;
    }
};
