// 最佳答案直接公式生成，外层遍历范围小太多了

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int u = 2; u <= sqrt(n); u++) {
            for (int v = 1; v < u; v++) {
                if (~(u - v) & 1 || gcd(u, v) != 1) continue;
                int c = u * u + v * v;
                if (c > n) continue;
                res += 2 * (n / c);
            }
        }
        return res;
    }
};

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int c = sqrt(a * a + b * b);
                if (a * a + b * b == c * c && c <= n) {
                    ++ans;
                    cout << a << " " << b << ""  << c << endl;
                }
            }
        }
        return ans;
    }
};