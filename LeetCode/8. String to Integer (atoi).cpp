// 题目本身不难，只是需要注意两个地方
// 第一是int的最大值和最小值的判断，两者不是直接乘以-1的
// 第二是字符一些边界case的判断，多跑跑然后看下没有通过的边界case几星

class Solution {
public:
    int myAtoi(string s) {
        int flag = 0;
        int res = 0;
        int digit = 0;
        for (auto c: s) {
            if (flag == 0 && (c =='-' || c == '+')) {
                flag = (c == '+' ? 1 : -1);
                continue;
            }
            
            if (c >= '0' && c <= '9') {
                if (flag == 0) {
                    flag = 1;
                }
                digit = c - '0';
                if ((INT32_MAX - digit) / 10 < res) {
                    if (flag == 1) {
                        return INT32_MAX;
                    }
                    else {
                        return INT32_MIN;
                    }
                    
                }
                res = res * 10 + digit;
            }
            else if (flag == 0 && c == ' ') {
                continue;
            }
            else {
                return res * flag;
            }
        }
        return res * flag;
    }
};