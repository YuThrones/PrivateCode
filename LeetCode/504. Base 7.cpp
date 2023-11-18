// 进制转换的题目思路很简单，求余直到为0就行，需要注意下处理负数就好


class Solution {
public:
    string convertToBase7(int num) {
        if (!num) return "0";
        string res = "";
        bool nega = num < 0 ? true : false;
        num = abs(num);
        while(num > 0) {
            res += to_string(num % 7);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        if (nega) return "-" + res;
        return res;
    }
};