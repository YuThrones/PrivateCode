// 简单的递归，处理好0还有1的basecase就行

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (n % 4 != 0) return false;
        return isPowerOfFour(n / 4);
    }
};