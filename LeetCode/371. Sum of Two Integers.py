# 这道题是用^和&来做，用^(异或)可以得到无进位加法的结果
# 用& 加上 << 可以得到进位的结果
# 一直重复加到没有进位就是答案

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;
            int carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
