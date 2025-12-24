没理解对意思，一开始以为是删除一个子字符串，结果是子序列，所以如果本身不是回文，只需要把其中一种字母删完就行，最多2步。

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.length() == 0) {
            return 0;
        }
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s[i] != s[s.length() - 1 - i]) {
                return 2;
            }
        }
        return 1;
    }
};