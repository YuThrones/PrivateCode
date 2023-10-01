// 一开始还在思考遍历字符比较，仔细一想其实就是单调栈的标准题型。

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }
        vector<char> stack;
        int i;
        for (i = 0; i < num.size(); ++i) {
            if (!k) break;
            while(stack.size() && stack[stack.size() - 1] > num[i] && k) {
                stack.pop_back();
                --k;
            }
            stack.push_back(num[i]);
        }
        while(k) {
            stack.pop_back();
            --k;
        }
        string res(stack.begin(), stack.end());
        res += num.substr(i, num.size() - i);
        
        int start = 0;
        for (; start < res.size(); ++start) {
            if (res[start] != '0') break;
        }
        res = res.substr(start, res.size() - start);
        if (!res.size()) res = "0";
        return res;
    }
};

int main() {
    string num = "1432219";
    int k = 3;
    Solution s;
    string res = s.removeKdigits(num, k);
    cout << res << endl;
}