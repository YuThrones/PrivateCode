// 这道题的重点在分析，首先从集合中只有一个空字符串开始，
// 去掉以当前位置的字符结尾的集合数量，把剩余字符串加上当前字符，减去原本的数量
// 就是这次单纯增加的字符串的数量，举例如下：
// abac
// 第一次 {}               
// 第二次 {} {a}           纯新增：{a}
// 第三次 {} {a} {b} {ab}  纯新增: {b} {ab}
// 第四次 {} {a} {b} {ab} {aa} {ba} {aba} 纯新增：{aa} {ba} {aba}
// 第五次 {} {a} {b} {ab} {aa} {ba} {aba} {c} {ac} {bc} {abc} {aac} {bac} {abac}  纯新增：{c} {ac} {bc} {abc} {aac} {bac} {abac}
// 每次要统计的就是当前字符作为结尾的数量的纯新增


#include<string>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int all = 1;
        int mod = 1000000007;
        int cnt[26] {0};
        for (auto&c :s) {
            int newAdd = (all - cnt[c - 'a'] + mod) % mod;
            cnt[c - 'a'] = (cnt[c - 'a'] + newAdd) % mod;
            all = (all + newAdd) % mod;
        }
        return (all + mod - 1) % mod;
    }
};

int main() {

    return 0;
}