// 26进制的转化

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int base = 1;
        int size = columnTitle.length();
        for (int i = size - 1; i >= 0; --i) {
            res += base * (columnTitle[i] - 'A' + 1);
            if (i != 0) {
                base *= 26;            
            }
        }
        return res;
    }
};