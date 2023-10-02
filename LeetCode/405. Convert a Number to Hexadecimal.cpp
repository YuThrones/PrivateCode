// 一开始还想着辗转相除法，后面想了下其实按字节扫描才是正道

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char dct[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
int mask = 15;

class Solution {
public:
    string toHex(int num) {
        if (!num) return "0";
        string res = "";
        for (int i = 0; i < 8 && num; ++i) {
            res += dct[num & mask];
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    for (int i = -33; i < 33; ++i)
        cout << s.toHex(i) << endl;
    s.toHex(-2147483648);
    return 0;
}