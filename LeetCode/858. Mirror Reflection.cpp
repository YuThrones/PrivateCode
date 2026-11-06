// 这道题能想到是变成直线，但是还是没想清楚
// 变成直线之后通过单元格就是解
// 然后根据奇偶性来判定结果
// 答案位置一定是p和q的最小公倍数
// 这时候算一下p和q分别有几个
// 如果有偶数个p，那就是在左边，只能是位置2
// 其他情况就是看q，判断下面还是上面

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        p /= g;
        q /= g;

        if (p % 2 == 0) return 2;
        if (q % 2 == 0) return 0;
        return 1;
    }
};