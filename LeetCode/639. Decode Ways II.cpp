// 典型动态规划，注意*不能代表0还有记得求模防溢出就行

#include<string>
using namespace std;

#define MODNUM 7 + 1000000000ll

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        long long dp[n + 1];
        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            if (s[i] == '*') {
                dp[i] = 9 * dp[i + 1];
                if (i + 1 < n) {
                    if (s[i + 1] == '*') {
                        dp[i] += 15 * dp[i + 2];
                    }
                    else if (s[i + 1] - '0' <= 6) {
                        dp[i] += 2 * dp[i + 2];
                    }
                    else {
                        dp[i] += dp[i + 2];
                    }
                }
            }
            else {
                dp[i] = dp[i + 1];
                if (i + 1 < n) {
                    if (s[i] == '1') {
                        if (s[i + 1] == '*') {
                            dp[i] += dp[i + 2] * 9;
                        }
                        else {
                            dp[i] += dp[i + 2];
                        }
                    }
                    else if (s[i] == '2') {
                        if (s[i + 1] == '*') {
                            dp[i] += dp[i + 2] * 6;
                        }
                        else if (s[i + 1] - '0' <= 6) {
                            dp[i] += dp[i + 2];
                        }
                    }
                }
            }
            dp[i] %= MODNUM;
        }

        return (int)dp[0];
    }
};

int main() {
    Solution sol;
    string s = "1*";
    int ans = sol.numDecodings(s);
    return 0;
}