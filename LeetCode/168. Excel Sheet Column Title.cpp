// 十进制转26进制，边界处理注意下就行，最快答案的coding更加简洁一点
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int rest = 0;
        while(columnNumber > 0) {
            rest = columnNumber % 26;
            if (rest == 0) {
                rest = 26;
            }
            columnNumber -= rest;
            columnNumber /= 26;
            char num = 'A' + rest - 1;
            res = "" + string(1, num) + res;
        }
        return res;
    }
};