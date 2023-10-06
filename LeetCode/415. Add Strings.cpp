// 模仿自己计算的方式写成代码就行，注意进位处理

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);
        string res;
        int carry = 0;
        int sum = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i >= 0 && j >= 0) {
            sum = num1[i] - '0' + num2[j] - '0' + carry;
            if (sum > 9) {
                carry = 1;
                res.push_back(sum - 10 + '0');
            }
            else {
                carry = 0;
                res.push_back(sum + '0');
            }
            --i;
            --j;
        }
        if (j < 0) {
            while(i >= 0) {
                sum = num1[i] - '0' + carry;
                if (sum > 9) {
                    carry = 1;
                    res.push_back(sum - 10 + '0');
                }
                else {
                    carry = 0;
                    res.push_back(sum + '0');
                }
                --i;
            }
        }
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }

    // string addStrings(string num1, string num2) {
    //     int maxSize = max(num1.size(), num2.size());
    //     num1 = string(maxSize - num1.size(), '0') + num1;
    //     num2 = string(maxSize - num2.size(), '0') + num2;
    //     string res;
    //     int carry = 0;
    //     int sum = 0;
    //     int mod = 0;
    //     for (int i = num1.size() - 1; i >= 0; --i) {
    //         sum = num1[i] - '0' + num2[i] - '0' + carry;
    //         carry = sum / 10;
    //         mod = sum % 10;
    //         res.push_back(mod + '0');
    //     }
    //     if (carry) res.push_back('1');
    //     reverse(res.begin(), res.end());
    //     return res;
    // }
};

int main() {
    Solution s;
    string res = s.addStrings("1", "9");

    return 0;
}