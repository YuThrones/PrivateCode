// 这题很简单，注意处理连续空格，还有最后一个segment就行

#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool lastSpace = true;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (!lastSpace) {
                    ++res;
                }
                lastSpace = true;
            }
            else {
                lastSpace = false;
            }
        }
        if (!lastSpace) {
            ++res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    sol.countSegments("Hello, my name is John");
    return 0;
}