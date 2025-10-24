#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int i = 0;
        while(i < s.length()) {
            if (i + 2 < s.length() && s[i + 2] == '#') {
                ans += ('a' + (stoi(s.substr(i, 2)) - 1));
                i += 3;
            }
            else {
                ans += ('a' + (s[i] - '0' - 1));
                i += 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.freqAlphabets("10#11#12");
    return 0;
}