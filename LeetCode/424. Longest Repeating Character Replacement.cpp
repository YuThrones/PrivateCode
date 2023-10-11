// 这题一开始的想法是递归然后加存储来做，但是复杂度明显爆炸
// 实际上不需要进行字符替换，只需要关注一个区间内的相同字符个数，其他的靠k判断能不能完全替换就行
// 然后找到最大区间，也就是转化为双指针问题

#include <string>
using namespace std;

class Solution {
public:

    int characterReplacement(string s, int k) {
        int charCount[26] = {};
        int maxLength = 0;
        int maxCharCount = 0; // 这里指的不是区间内char最多的字符的当前数量，而是有可能区间内char最多的字符有可能推高最大长度值的数量，有可能左边区间向右导致实际值变小，但是不会影响最终结果
        int left = 0;
        int right = 0;
        while(right < s.length()) {
            ++charCount[s[right] - 'A'];
            maxCharCount = max(maxCharCount, charCount[s[right] - 'A']);
            // 主要区间不大于最大字符数量+k，说明都可以替换后让区间整体变成相同字符
            if (right - left + 1 > maxCharCount + k) {
                --charCount[s[left++] - 'A'];
            }
            maxLength = max(maxLength, right - left + 1);
            ++right;
        }
        return maxLength;
    }
};


int main() {
    Solution s;
    string str = "AABABBA";
    int k = 1;
    int res=s.characterReplacement(str, k);
    return 0;
}