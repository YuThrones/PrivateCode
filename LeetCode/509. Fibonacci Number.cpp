class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int num1 = 0;
        int num2 = 1;
        int num3;
        for (int i = 2; i <= n; ++i) {
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        return num3;
    }
};