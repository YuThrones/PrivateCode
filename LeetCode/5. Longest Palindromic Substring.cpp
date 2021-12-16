#include<iostream>
using namespace std;

// 使用Manacher算法求解，利用回文串对称位置的性质来加速计算，在线性时间内完成求解。
// https://zh.wikipedia.org/wiki/%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2

class Solution {
public:
    string longestPalindrome(string s) {
        // 插入字符$把所有长度的字符串都处理成奇数
        string new_s = "";
        for (int i = 0; i < s.length(); ++i) {
            new_s = new_s + '$' + s[i];
        }
        new_s += '$';
        int c = 0; //当前检查的中心
        int r = 0; //当前检查的中心的半径
        int* record = new int[new_s.length()];
        while (c < new_s.length()) {
            // 常规的检查一个中心是否对称
            while(c - r >= 0 && c + r < new_s.length() && new_s[c - r] == new_s[c + r]) {
                ++r;
            }
            record[c] = r;

            // 使用Manacher算法，计算右边界之内的回文串
            int lc = c;
            int lr = r;
            r = 0;
            int rb = lc + lr;
            while(++c < rb) {
                // 算出对称位置
                int mc = 2 * lc - c;
                if (c + record[mc] < rb) {
                    // 对称位置的回文串没有达到左边界，只需要直接把当前位置设置为和对称位置半径相同
                    record[c] = record[mc];
                }
                else if (c + record[mc] == rb) {
                    // 对称位置的回文串刚好到达左边界，那么有可能右边还能构成回文，起码长度为当前长度，需要继续算
                    r = record[mc];
                    break;
                }
                else {
                    // 对称位置超了左边界，那么可以右边最多半径到底右边界，否则lc的半径就不止这么多了
                    record[c] = rb - c;
                }
            }
        }
        int max_c = 0; // 半径最长的检查的中心
        int max_r = 0; // 最长的半径
        for (int i = 0; i < new_s.length(); ++i) {
            if (record[i] > max_r) {
                max_c = i;
                max_r = record[i];
            }
        }
        // 把所有$都去掉得出正确答案
        string res = "";
        for (int i = max_c - max_r + 1; i < max_c + max_r; ++i) {
            if (new_s[i] != '$') {
                res = res + new_s[i];
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    string res = s.longestPalindrome("babad");
    cout << "结果" << res << endl;
    return 0;
}