// 思路很简单，就是枚举前两个数，然后看看能不能把整个数组推理完，不能就截断
// 需要考虑的主要是边界条件，别溢出之类的

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break;

            long long a = 0;
            for (int p = 0; p < i; ++p) {
                a = a * 10 + (num[p] - '0');
                if (a > INT_MAX) break;
            }
            if (a > INT_MAX) break;

            // 保证 i + j 后面至少还留一个数字给第三个数
            for (int j = 1; i + j < n; ++j) {
                if (num[i] == '0' && j > 1) break;

                long long b = 0;
                bool ok = true;
                for (int p = i; p < i + j; ++p) {
                    b = b * 10 + (num[p] - '0');
                    if (b > INT_MAX) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;

                vector<int> cur;
                cur.push_back((int)a);
                cur.push_back((int)b);

                int pos = i + j;

                while (pos < n) {
                    long long c = (long long)cur[cur.size() - 1] + cur[cur.size() - 2];
                    if (c > INT_MAX) {
                        cur.clear();
                        break;
                    }

                    string s = to_string(c);
                    if (pos + (int)s.size() > n ||
                        num.substr(pos, s.size()) != s) {
                        cur.clear();
                        break;
                    }

                    cur.push_back((int)c);
                    pos += s.size();
                }

                if (pos == n && cur.size() >= 3) {
                    return cur;
                }
            }
        }

        return {};
    }
};