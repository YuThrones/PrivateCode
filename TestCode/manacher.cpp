#include<iostream>
using namespace std;

int* getPalindromeRadiusArray(string s) {
    // 计算出一个回文半径数组并返回
    string str = "";
    for (int i = 0; i < s.length(); ++i) {
        str = str + '#' + s[i];
    }
    str += '#';

    int *res = new int[str.length()];
    int right = -1;
    int center = -1;
    int index = 0;
    while (index < str.length()) {
        res[index] = right > index ? min(right - index, res[center * 2 - index]) : 1;
        while (index + res[index] < str.length() && index - res[index] >= 0) {
            if (str[index + res[index]] == str[index - res[index]]) {
                ++res[index];
            }
            else {
                break;
            }
        }
        if (index + res[index] > right) {
            right = index + res[index];
            center = index;
        }
        ++index;
    }

    // for (int i = 0; i < str.length(); ++i) {
    //     cout << str[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < str.length(); ++i) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;
    return res;
}

int main() {
    string input = "12324235";
    int * res = getPalindromeRadiusArray(input);
    return 0;
}